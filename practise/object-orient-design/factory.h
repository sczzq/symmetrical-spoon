#ifndef _factory_
#define _factory_

#include "base_class.h"

class factory {
	public:
		base_class *GetImplementation(const string &className);
};

#endif

