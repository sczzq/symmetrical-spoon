#ifndef _BASE_CLASS_
#define _BASE_CLASS_

#include <string>

using std::string;

class base_class {
	public:
		base_class();
		virtual ~base_class() = 0;

		virtual string GetClassName() = 0;
};

#endif

