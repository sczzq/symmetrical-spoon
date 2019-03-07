#ifndef _Sender__
#define _Sender__

namespace perf_test_tool {

using std::string;

/*
 */

class SenderSocket : public SenderInterface {
	public:
		SenderSocket();
		virtual ~SenderSocket();

		const string type = "SOCKET";

		virtual int send(const AudioPiece audiopiece);
		virtual int recv(Result& result);
};

};

#endif

