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

		vector<shared_ptr<Invoker>> invokers;

		// threads to run invoker task.
		vector<thread> threads;

		atomic<int> invoker_count;

		// Run will create invoker_count threads.
		void Run();

		// Stop will stop all threads.
		void Stop();

		void Status();

		// donot expliciting waiting thread use join(),
		// instand to check invoker_count 
		// and then InvokePolicy could stop thread at sometime.
		// interleave maybe 1 second to check invoker_count.
		void Waiting();

		// if finished, Invoker will call subCount.
		void subCount() { --invoker_count; };

		int id;
};

};

#endif

