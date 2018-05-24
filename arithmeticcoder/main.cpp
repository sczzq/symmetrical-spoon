/*************************************************************************
	> File Name: main.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 14 Apr 2017 02:59:12 PM CST
 ************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

#include "ModelOrder0C.h"

// signature: "ACMC" (0x434D4341, intel byte order)
// (magic number for recognition of encoded files)

const int g_Signature = 0x434D4341;

int 
//__cdecl
main(int argc, char *argv[])
{
	cout << "Arithmetic Coding" << endl;
	if( argc != 3 )
	{
		cout << "Syntax: AC source target" << endl;
		return 1;
	}
	fstream source, target;
	ModelI* model;

	// choose model, here just order-0
	model = new ModelOrder0C;
	source.open( argv[1], ios::in | ios::binary );
	target.open( argv[2], ios::out | ios::binary );
	if( !source.is_open() )
	{
		cout << "Cannot open input stream";
		return 2;
	}
	if( !target.is_open() )
	{
		cout << "Cannot open output stream";
		return 3;
	}
	unsigned int signature;
	source.read(reinterpret_cast<char*>(&signature),sizeof(signature));
	if( signature == g_Signature )
	{
		cout << "Decoding " << argv[1] << " to " << argv[2] << endl;
		model->Process( &source, &target, MODE_DECODE );
	}
	else
	{
		cout << "Encoding " << argv[1] << " to " << argv[2] << endl;
		source.seekg( 0, ios::beg );
		target.write( reinterpret_cast<const char*>(&g_Signature),
				sizeof(g_Signature) );
		model->Process( &source, &target, MODE_ENCODE );
	}

	source.close();
	target.close();
	return 0;
}




