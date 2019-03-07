#ifndef _Output__
#define _Output__

namespace perf_test_tool {

using std::string;

/*
 */

class SenderFactory {
	public:
		static std::shared_ptr<SenderInterface> Produce(const string instance_type);

		// Asynchronous Operator.
//		static std::shared_ptr<AsyncSenderInterface> Produce(const string instance_type);
};

};

#endif

