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

class AudioStream {
	public:
		AudioStream();
		~AudioStream();

		char *data;

		AudioPiece GetAudioPiece(AudioInfo audioinfo);

		// unit: byte.
		int length;

		// unit: millisecond.
		int duration;

		int format;
};

};

#endif

