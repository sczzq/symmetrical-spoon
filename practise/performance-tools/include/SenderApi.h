#ifndef _Sender__
#define _Sender__

namespace perf_test_tool {

using std::string;

/*
 */

class SenderApi : public SenderInterface {
	public:
		SenderApi();
		virtual ~SenderApi();

		virtual int send(const AudioPiece audiopiece);
		virtual int recv(Result& result);
};

};

#endif

