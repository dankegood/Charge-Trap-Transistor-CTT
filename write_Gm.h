#ifndef __WRITE_GM__
#define __WRITE_GM__

#include "header.h"
#include "calculate_Gm.h"

void WriteFunc(FILE * fp1, FILE * fp2, float * ptr1, float * ptr2, float * ptr3, float * ptr4, float * ptr5)
{
	char str[200];
	char strCopy1[25], strCopy2[25];
	float Gm_Id = 0.0;
	float Gm_Is = 0.0;

	if (fp1 == NULL || fp2 == NULL)
	{
		puts("FILE OPEN FAIL! \n");
		return;
	}

	fgets(str, sizeof(str), fp1);
	fputs(str, fp2);

	for (int i = 0; i < 60000; i++)	// Change!! (Total row - 1)
	{
		int count = 0;

		Gm_Id = CalGm(&ptr1[i], &ptr2[i]);
		ptr4[i] = Gm_Id;
		Gm_Is = CalGm(&ptr1[i], &ptr3[i]);
		ptr5[i] = Gm_Is;

		sprintf(strCopy1, "%e", Gm_Id);
		strcat(strCopy1, "\t");
		sprintf(strCopy2, "%e", Gm_Is);
		strcat(strCopy2, "\n");

		fgets(str, sizeof(str), fp1);

		while (1)
		{
			if (str[count] == '\n')
			{
				if (str[count - 1] == '\t')
					str[count] = '\0';

				else
				{
					str[count] = '\t';
					str[count + 1] = '\0';
				}
				break;
			}
			count++;
		}

		strcat(str, strCopy1);
		strcat(str, strCopy2);
		fputs(str, fp2);
		// memset(strCopy, '\0', sizeof(strCopy)); -> unnecessary
	}
}

#endif