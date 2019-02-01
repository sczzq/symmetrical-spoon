
#include "factory.h"

#include "implementation1.h"
#include "implementation2.h"
#include "implementation3.h"

#include <string>

using std::string;

base_class *factory::GetImplementation(const string &className)
{
	if ("implementation1" == className)
	{
		return new implementation1();
	}
	else if ("implementation2" == className)
	{
		return new implementation2();
	}
	else if ("implementation3" == className)
	{
		return new implementation3();
	}
	return NULL;
}

