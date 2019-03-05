#ifndef _Audio_Data__
#define _Audio_Data__

namespace performance {

using std::string;

/*
 */

class AudioPiece {
	public:
		AudioPiece();
		~AudioPiece();

		char *data;
		int length;
		int format;
};

class AudioStream {
	public:
		AudioStream();
		~AudioStream();

		char *data;
		int length;
		int format;
};

};

#endif

