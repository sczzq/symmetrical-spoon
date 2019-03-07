#ifndef _Output__
#define _Output__

namespace perf_test_tool {

using std::string;

/*
 */

class OutputFile : public OutputInterface {
	public:
		OutputFile(ConfigSlice conf);
		~OutputFile();

		string name;

		ofstream ostrm;

		void Run();
		void Stop();

		int Push(TimestampInterface& ts);

		ConfigSlice config;
};

};

#endif

