#ifndef _Output__
#define _Output__

namespace perf_test_tool {

using std::string;

/*
 */

class OutputFactory {
	public:
		static std::shared_ptr<OutputInterface> Produce(const string instance_type);
};

};

#endif

