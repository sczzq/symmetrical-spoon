#include "implementation1.h"

#include <iostream>

using namespace std;

implementation1::implementation1()
	: className("implementation1")
{
	cout << "construct implementation1" << endl;
}

implementation1::~implementation1()
{
	cout << "deconstruct implementation1" << endl;
}

string implementation1::GetClassName()
{
	return className; 
}

