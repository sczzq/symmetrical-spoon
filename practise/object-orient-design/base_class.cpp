#include "base_class.h"

#include <iostream>

using std::cout;
using std::endl;

base_class::base_class()
{
	cout << "construct base_class" << endl;
}

base_class::~base_class()
{
	cout << "deconstruct base_class" << endl;
}

