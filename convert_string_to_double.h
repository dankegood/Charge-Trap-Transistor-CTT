#ifndef __CONVERT_STRING_TO_DOUBLE__
#define __CONVERT_STRING_TO_DOUBLE__

#include "header.h"

float StringToDouble(char * str)
{
	float num = atof(str);
	return num;
}

#endif