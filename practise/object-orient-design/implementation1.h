#include "base_class.h"

#ifndef _implementation1_
#define _implementation1_

class implementation1 : public base_class 
{
	public:
		implementation1();
		virtual ~implementation1();

		virtual string GetClassName();
	private:
		string className;
};

#endif

