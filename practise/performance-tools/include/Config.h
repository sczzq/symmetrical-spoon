#ifndef _Config__
#define _Config__

#include <string>
#include <map>
#include <vector>
#include <string>

namespace perf_test_tool {

using std::string;
using std::map;
using std::vector;

// slice type in configs:
//		send_policy
//		interface
//		output
//		audio
//		result
//		log
//		invoker_group
//		invoke_policy
class ConfigSlice {
	public:
		map<string, map<string,string>> configs;

		string sequence();
		string json();
};

// incude slices which invoker needed.
//		send_policy
//		interface
//		output
//		audio
class InvokerConfigs {
	public:
		map<string, ConfigSlice> configs;

		string sequence();
		string json();
};

// include every slice in config file.
// call InvokePolicy to work one after another.
class Config {
	public:
		InvokerConfigs configs;

		// pass configs to invokepolicys.
		vector<InvokePolicy> invokepolicys;

		string sequence();
		string json();
};

};

#endif

