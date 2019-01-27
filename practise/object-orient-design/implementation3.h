#include "base_class.h"

#ifndef _implementation3_
#define _implementation3_

class implementation3 : public base_class 
{
	public:
		implementation3();
		virtual ~implementation3();

		virtual string GetClassName();
	private:
		string className;
};

#endif

