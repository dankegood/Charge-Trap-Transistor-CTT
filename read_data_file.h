#ifndef __READ_DATA_FILE__
#define __READ_DATA_FILE__

#include "header.h"
#include "find_val.h"

void ReadFunc(FILE * fp1, FILE * fp2, float * ptr1, float * ptr2, float * ptr3)
{
	char str[200];

	if (fp1 == NULL || fp2 == NULL)
	{
		puts("FILE OPEN FAIL! \n");
		return;
	}

	fgets(str, sizeof(str), fp1);

	for (int i = 0; i < 60000; i++)	// Change!! (Total row - 1)
	{
		fgets(str, sizeof(str), fp1);
		*(ptr1 + i) = FindVg(str);
		*(ptr2 + i) = FindId(str);
		*(ptr3 + i) = FindIs(str);
	}
}

#endif