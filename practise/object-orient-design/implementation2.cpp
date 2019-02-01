#include "implementation2.h"

#include <iostream>

using namespace std;

implementation2::implementation2()
	: className("implementation2")
{
	cout << "construct implementation2" << endl;
}

implementation2::~implementation2()
{
	cout << "deconstruct implementation2" << endl;
}

string implementation2::GetClassName()
{
	return className; 
}

