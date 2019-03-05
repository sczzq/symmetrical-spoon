#ifndef _Invoke_Policy__
#define _Invoke_Policy__

namespace performance {

#include <string>
#include <vector>
#include <atomic>
#include "Invoker.h"

using std::string;

/*
 */

class  InvokePolicy {
	public:
		InvokePolicy();
		~InvokePolicy();

		vector<Invoker> invokers;

		int waiting();

		int getStatus();

		atomic<int> invoker_count;

};

};

#endif

