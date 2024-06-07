#ifndef __FIND_VAL__
#define __FIND_VAL__

#include "header.h"
#include "convert_string_to_double.h"
#include "find_abso_val.h"

float FindVg(char * str)
{
	int pos = 0;
	int tabCount = 0;
	char strCopy[25];
	float Vg = 0.0;

	while (1)
	{
		if (str[pos] == '\t')
			tabCount++;
		pos++;

		if (tabCount == 10)
		{
			int i = 0;

			while (1)
			{
				if (str[pos] == '\t')
				{
					strCopy[i] = '\0';
					break;
				}
				strCopy[i] = str[pos];
				pos++, i++;
			}
			break;
		}
	}

	if (((*strCopy) >= 48 && (*strCopy) <= 57) || ((*strCopy) == 45))
		Vg = StringToDouble(strCopy);

	return Vg;
}

float FindId(char * str)
{
	int pos = 0;
	int tabCount = 0;
	char strCopy[25];
	float Id = 0.0;

	while (1)
	{
		if (str[pos] == '\t')
			tabCount++;
		pos++;

		if (tabCount == 12)
		{
			int i = 0;

			while (1)
			{
				if (str[pos] == '\t')
				{
					strCopy[i] = '\0';
					break;
				}
				strCopy[i] = str[pos];
				pos++, i++;
			}
			break;
		}
	}

	if (((*strCopy) >= 48 && (*strCopy) <= 57) || ((*strCopy) == 45))
		Id = StringToDouble(strCopy);

	return AbsoVal(Id);
}

float FindIs(char * str)
{
	int pos = 0;
	int tabCount = 0;
	char strCopy[25];
	float Is = 0.0;

	while (1)
	{
		if (str[pos] == '\t')
			tabCount++;
		pos++;

		if (tabCount == 13)
		{
			int i = 0;

			while (1)
			{
				if (str[pos] == '\t')
				{
					strCopy[i] = '\0';
					break;
				}
				strCopy[i] = str[pos];
				pos++, i++;
			}
			break;
		}
	}

	if (((*strCopy) >= 48 && (*strCopy) <= 57) || ((*strCopy) == 45))
		Is = StringToDouble(strCopy);

	return AbsoVal(Is);
}

#endif
