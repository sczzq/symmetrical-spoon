#ifndef _Audio_Data__
#define _Audio_Data__

namespace perf_test_tool {

using std::string;

/*
 */

class AudioInfo {
	public:
		AudioInfo();
		~AudioInfo();

		// unit: millisecond.
		int start;

		// unit: millisecond.
		int duration;
};

class AudioPiece {
	public:
		AudioPiece();
		~AudioPiece();

		char *data;

		// unit: byte.
		int length;

		// unit: millisecond.
		int duration;

		int format;
};

// audio file in directory.
// read all audio files into memory
// sort by ascci sequence.
class AudioStream {
	public:
		AudioStream(ConfigSlice conf);
		~AudioStream();

		char *data;

		AudioPiece getAudioPiece(AudioInfo audioinfo);

		// unit: byte.
		int length;

		// unit: millisecond.
		int duration;

		int format;

		ConfigSlice config;
};

};

#endif

