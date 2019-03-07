#ifndef _Invoker__
#define _Invoker__

namespace perf_test_tool {

using std::string;

/*
 */

class Invoker {
	public:
		Invoker(InvokerConfigs conf);
		~Invoker();

		// in: NULL, out: AudioInfo
		std::shared_ptr<SendPolicyInterface> sendPolicy;

		// in: AudioInfo, out: AudioPiece
		std::shared_ptr<AudioStream> audio;

		// in: AudioPiece, out: Timestamp
		std::shared_ptr<SenderInterface> sender;

		// in: Timestamp, out: NULL
		std::shared_ptr<OutputInterface> output;

		void Run();
		void Stop();
		int  Status();

		InvokerConfigs configs;

		int id;
};

};

#endif

