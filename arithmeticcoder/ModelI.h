/*************************************************************************
	> File Name: modelI.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 14 Apr 2017 02:49:48 PM CST
 ************************************************************************/

#ifndef __MODELI_H__
#define __MODELI_H__
#include "ArithmeticCoderC.h"
enum ModeE
{
	MODE_ENCODE = 0,
	MODE_DECODE
};
class ModelI
{
	public:
		void Process( fstream *source, fstream *target, ModeE mode );
	protected:
		virtual void Encode() = 0;
		virtual void Decode() = 0;
		ArithmeticCoderC mAC;
		fstream *mSource;
		fstream *mTarget;
};
#endif
