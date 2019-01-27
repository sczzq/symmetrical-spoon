#include "implementation3.h"

#include <iostream>

using namespace std;

implementation3::implementation3()
	: className("implementation3")
{
	cout << "construct implementation3" << endl;
}

implementation3::~implementation3()
{
	cout << "deconstruct implementation3" << endl;
}

string implementation3::GetClassName()
{
	return className; 
}

