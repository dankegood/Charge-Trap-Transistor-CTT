#ifndef __FIND_ABSO_VAL__
#define __FIND_ABSO_VAL__

#include "header.h"

float AbsoVal(float num)
{
	if (num < 0.0)
		return (num * -1);
	else
		return num;
}

#endif