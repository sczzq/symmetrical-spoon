#ifndef _Config__
#define _Config__

namespace performance {

using std::string;

/*
 */

class Config {
	public:
		Config();
		~Config();

		vector<InvokePolicy> invokepolicys;
};

};

#endif

