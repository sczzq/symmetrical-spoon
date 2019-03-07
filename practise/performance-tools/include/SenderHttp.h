#ifndef _Sender__
#define _Sender__

namespace perf_test_tool {

using std::string;

/*
 */

class SenderHTTP : public SenderInterface {
	public:
		SenderHTTP();
		virtual ~SenderHTTP();

		virtual int send(const AudioPiece audiopiece);
		virtual int recv(Result& result);
};

};

#endif

