/*************************************************************************
	> File Name: ModelI.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 14 Apr 2017 02:50:26 PM CST
 ************************************************************************/

#include "ModelI.h"

void ModelI::Process( fstream *source, fstream *target, ModeE mode )
{
	mSource = source;
	mTarget = target;
	if( mode == MODE_ENCODE )
	{
		mAC.SetFile( mTarget );
		// encode
		Encode();
		mAC.EncodeFinish();
	}
	else // MODE_DECODE
	{
		mAC.SetFile( mSource );
		mAC.DecodeStart();

		// decode
		Decode();
	}
};
