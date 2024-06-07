#ifndef __CALCULATE_GM__
#define __CALCULATE_GM__

#include "header.h"

float CalGm(float * ptr1, float * ptr2)
{
	if ((*ptr1) == 0)
		return 0.0;

	else
		return ((*ptr2) - (*(ptr2 - 1))) / ((*ptr1) - (*(ptr1 - 1)));
}

#endif