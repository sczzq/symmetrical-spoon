#ifndef _Invoke_Policy__
#define _Invoke_Policy__

namespace perf_test_tool {

#include <string>
#include <vector>
#include <atomic>
#include "Invoker.h"

using std::string;
using std::vector;
using std::atomic;

/*
 */

// get invoke_policy config by id.

class InvokePolicy {
	public:
		InvokePolicy(int id, Configs configs);
		~InvokePolicy();

		vector<Invoker> invokers;

		atomic<int> invoker_count;

		void Run();
		void Stop();
		void Status();
		void Waiting();

		int id;
};

};

#endif

