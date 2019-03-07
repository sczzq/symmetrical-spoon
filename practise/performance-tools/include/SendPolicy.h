#ifndef _Send_Policy__
#define _Send_Policy__

namespace perf_test_tool {

#include <string>
#include <vector>
#include <chrono>

#include "AudioData.h"

using std::string;
using std::vector;
using std::chrono::steady_clock;

/*
 * Valid sequence.
 * 1 2 3 4 5 6 7, is trival case.
 * 1-n means 1 2 3 4 5 6 ... n
 *     example
 *			1-7 means 1 2 3 4 5 6 7
 * 1-2 4-5 means 1 2 4 5
 * 1-2 4 5 8-10 means 1 2 4 5 8 9 10
 * 1 2-4 6-8 means 1 2 3 4 6 7 8
 *
 * assume total length of the data is 70 bytes,
 * piece_length is 10 bytes.
 *
 * then 1-2 4-5 means we will send first 20 bytes,
 * and then (excluded) 40th byte upto 50th bytes, 
 *
 * total data:
 * |  10    |   10    |   10    |   10    |   10    |   10    |   10    |   10    |      
 * ................................................................................
 * send data:
 * |  10    |   10    |   10    |   10    |   10    |   10    |   10    |   10    |      
 * ....................          ..........
 */

class SendPolicy {
	public:
		SendPolicy(string id, ConfigSlice conf);
		~SendPolicy();

		// this function will parse the string,
		// and then set it to ids and other members.
		// then the older one is replaced by the newer one.
		int setPolicy(ConfigSlice conf);

		// if send strategy is analog realtime
		// this call maybe blocked to wait next time point.
		AudioInfo GetNextPiece();

		// use this index to get 
		//		next id in ids.
		//		next start-point in starts.
		//		next duration in piece_durations,
		//		next length in piece_lengths.
		int next_index;

		// sequence id.
		vector<int> ids;

		// start point.
		// accumulating point in the audio stream.
		vector<int> starts;

		// byte length
		int piece_length;
		vector<int> piece_lengths;

		// the durations of every piece maybe diff.
		// if same, just use one parameter is OK.
		// if diff, then use the vector to store them.
		int piece_duration;
		vector<int> piece_durations;

		ConfigSlice config;
};

};

#endif

