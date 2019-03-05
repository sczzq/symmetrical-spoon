#ifndef _Sender__
#define _Sender__

namespace performance {

using std::string;

/*
 */

class Sender {
	public:
		Sender();
		~Sender();

		int sync;

		int send();
		int recv();

		void *callback();

		Socket socket;
		HttpClient httpclient;
		WebSocketClient websocketclient;
};

};

#endif

