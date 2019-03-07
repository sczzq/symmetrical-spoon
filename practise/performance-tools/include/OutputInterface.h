#ifndef _Output__
#define _Output__

namespace perf_test_tool {

using std::string;

/*
 */

class OutputInterface {
	public:
		std::atomic<bool> status;
		std::mutex mtx;
		std::condition_variable cv;

		void Run();
		void Stop();

		int Push(TimestampInterface& ts);

	private:
		OutputInterface();
		virtual ~OutputInterface();
};

};

#endif

