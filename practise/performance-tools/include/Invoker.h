#ifndef _Invoker__
#define _Invoker__

namespace performance {

using std::string;

/*
 */

class Invoker {
	public:

		Invoker();
		~Invoker();

		SendPolicy sendPolicy;

		Sender sender;

		Output output;

		int status;
};

};

#endif

