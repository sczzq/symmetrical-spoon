#include "base_class.h"

#ifndef _implementation2_
#define _implementation2_

class implementation2 : public base_class 
{
	public:
		implementation2();
		virtual ~implementation2();

		virtual string GetClassName();
	private:
		string className;
};

#endif

