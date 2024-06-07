#ifndef __WRITE_GM_MAX__
#define __WRITE_GM_MAX__

#include "header.h"

void WriteMaxFunc(FILE * fp1, FILE * fp2, float * ptr1, float * ptr2)
{
	char str[200];
	char strCopy1[25], strCopy2[25];
	float Gm_Id_Max = 0.0;
	float Gm_Is_Max = 0.0;

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

		if (ptr1[i] == 0.0)
		{
			Gm_Id_Max = ptr1[i + 1];

			int j = 2;

			while ((ptr1[i + j] != 0.0) && ((i + j) != 60000))	// Change!! (Total row - 1)
			{
				if (Gm_Id_Max < ptr1[i + j])
					Gm_Id_Max = ptr1[i + j];
				j++;
			}
		}

		if (ptr2[i] == 0.0)
		{
			Gm_Is_Max = ptr2[i + 1];

			int j = 2;

			while ((ptr2[i + j] != 0.0) && ((i + j) != 60000))	// Change!! (Total row - 1)
			{
				if (Gm_Is_Max < ptr2[i + j])
					Gm_Is_Max = ptr2[i + j];
				j++;
			}
		}

		sprintf(strCopy1, "%e", Gm_Id_Max);
		strcat(strCopy1, "\t");
		sprintf(strCopy2, "%e", Gm_Is_Max);
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