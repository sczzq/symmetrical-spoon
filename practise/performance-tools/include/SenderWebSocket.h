#ifndef _Sender__
#define _Sender__

namespace perf_test_tool {

using std::string;

/*
 */

class SenderWebSocket : public SenderInterface {
	public:
		SenderWebSocket();
		virtual ~SenderWebSocket();

		virtual int send(const AudioPiece audiopiece);
		virtual int recv(Result& result);
};

};

#endif

