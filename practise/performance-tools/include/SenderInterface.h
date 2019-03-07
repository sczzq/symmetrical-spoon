#ifndef _Sender__
#define _Sender__

namespace perf_test_tool {

using std::string;

/*
 */

class SenderInterface {
	public:
		SenderInterface();
		virtual ~SenderInterface();

		// set by children class.
		// used by SenderFactory to generate new object.
		string type;

		virtual int send(const AudioPiece audiopiece) = 0;
		virtual int recv(Result& result) = 0;

		ConfigSlice configslice;
};

};

#endif

