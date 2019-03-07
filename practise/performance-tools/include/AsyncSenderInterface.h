#ifndef _Sender__
#define _Sender__

namespace perf_test_tool {

using std::string;

/*
 */

class AsyncSenderInterface {
	public:
		AsyncSenderInterface();
		virtual ~AsyncSenderInterface();

		virtual int send(const AudioPiece audiopiece) = 0;

		ConfigSlice configslice;
};

};

#endif

