#include "header.h"
#include "convert_string_to_double.h"
#include "find_abso_val.h"
#include "read_data_file.h"
#include "find_val.h"
#include "calculate_Gm.h"
#include "write_Gm.h"
#include "write_Gm_max.h"

int main(void)
{
	FILE * fpR = fopen("B1_M1_FwdMode.txt", "rt");	// File name can be changed
	FILE * fpW = fopen("B1_M1_FwdMode_Cal.txt", "wt");	// File name can be changed

	float arrVg[60000], arrId[60000], arrIs[60000], arrGm_Id[60000], arrGm_Is[60000]; // Change!! (Total row - 1)
	ReadFunc(fpR, fpW, arrVg, arrId, arrIs);
	fclose(fpR);

	fpR = fopen("B1_M1_FwdMode.txt", "rt");	// File name can be changed
	WriteFunc(fpR, fpW, arrVg, arrId, arrIs, arrGm_Id, arrGm_Is);
	fclose(fpR);
	fclose(fpW);

	fpR = fopen("B1_M1_FwdMode_Cal.txt", "rt");	// File name can be changed
	fpW = fopen("B1_M1_FwdMode_Max_Cal.txt", "wt");	// File name can be changed
	WriteMaxFunc(fpR, fpW, arrGm_Id, arrGm_Is);

	fclose(fpR);
	fclose(fpW);
	return 0;
}