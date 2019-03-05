#ifndef _Send_Policy__
#define _Send_Policy__

namespace performance {

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
		// this function will parse the string,
		// and then set it to ids and other members.
		int setPolicy(string policy_str);

		// if send strategy is analog realtime
		// this call maybe blocked to wait next time point.
		AudioPiece GetNextPiece();

		// sequence id.
		vector<int> ids;

		// byte length
		int piece_length;
		vector<int> piece_lengths;

		// the durations of every piece maybe diff.
		// if same, just use one parameter is OK.
		// if diff, then use the vector to store them.
		int piece_duration;
		vector<int> piece_durations;

		// analog realtime
		// as soon as possible
		int strategy;

		// before return by GetNextPiece to set cur.
		// and
		// next GetNextPiece to use cur to get the sleeping time or blocking time.
		stready_clock::time_point cur;
};

};

#endif

