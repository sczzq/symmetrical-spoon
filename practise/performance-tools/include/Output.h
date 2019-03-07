#ifndef _Output__
#define _Output__

namespace perf_test_tool {

using std::string;

/*
 */

class Output : public OutputInterface {
	public:
		std::string filename;
		std::ofstream ostrm;

		void Run();
		void Stop();

		int Push(TimestampInterface& ts);

		Output();
		override ~Output();

		ConfigSlice configslice;
};

};

#endif

