#ifndef _Output__
#define _Output__

namespace performance {

using std::string;

/*
 */

class Output {
	public:
		// disk, socket
		int type;

		// filename, ip:port
		string path;

		int write();

		ostream os;
		Socket socket;
};

};

#endif

