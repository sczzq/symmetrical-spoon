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

		int setInvokePolicy(InvokePolicy *p);

		// in: NULL, out: AudioInfo
		std::shared_ptr<SendPolicyInterface> sendpolicy;

		// in: AudioInfo, out: AudioPiece
		std::shared_ptr<AudioStream> audio;

		// in: AudioPiece, out: Timestamp
		std::shared_ptr<SenderInterface> sender;

		// in: Timestamp, out: NULL
		std::shared_ptr<OutputInterface> output;

		// entry of thread.
		static void Run(shared_ptr<Invoker> this_);

		void Stop();

		// return finished piece.
		int  Status();

		InvokerConfigs configs;

		// just a pointer
		// set by passed this in InvokePolicy to construct Invoker.
		// donot need to release this pointer.
		// Invoke donot own this pointer.
		// Invoke will call InvokePolicy::Sub to update the alive Invoker.
		InvokePolicy *invokepolicy;

		int id;
};

};

#endif

