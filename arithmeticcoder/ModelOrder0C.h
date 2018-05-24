/*************************************************************************
	> File Name: ModelOrder0C.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 14 Apr 2017 02:51:31 PM CST
 ************************************************************************/

#ifndef __MODELORDER0C_H__
#define __MODELORDER0C_H__
#include "ModelI.h"
class ModelOrder0C : public ModelI
{
	public:
		ModelOrder0C();
	protected:
		void Encode();
		void Decode();
		unsigned int mCumCount[ 257 ];
		unsigned int mTotal;
};
#endif
