#include "T2P.h"
#include <stdlib.h>
#include <string.h>

char TCodeArray[MAX_CODE_COUNT][256];
int main()
{
	TCode TCodeList[MAX_CODE_COUNT]; // 三地址码列表
	PCode PCodeList[MAX_CODE_COUNT]; // P-代码列表

	// 将三地址码列表和P-代码列表的内容清空
	memset(TCodeList, 0, sizeof(TCodeList));
	memset(PCodeList, 0, sizeof(PCodeList));

	//
	// 初始化三地址码列表
	//
#ifdef CODECODE_CI
	InitTCodeList_CI(TCodeList); // 此行代码在线上流水线运行
#else
	InitTCodeList(TCodeList); // 此行代码在 CP Lab 中运行
#endif

	//
	// 将三地址码转换为P-代码
	//
	T2P(TCodeList, PCodeList);

	//
	// 输出P-代码
	//
	OutputResult(PCodeList);

	return 0;
}

/*
功能：
	将三地址码转换为 P-代码。
	
参数：
	TCodeList -- 三地址码列表指针。
	PCodeList -- P-代码列表指针。
*/
void T2P(TCode *TCodeList, PCode *PCodeList)
{
	int TIndex = 0; // 三地址码列表游标
	int PIndex = 0; // P-代码列表游标

	for (; TCodeList[TIndex].Kind != 0; TIndex++)
	{
		switch (TCodeList[TIndex].Kind)
		{
		case t_rd:

			// 产生一条 lda 指令
			PCodeList[PIndex].Kind = p_lda;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			PIndex++;

			// 产生一条 rdi 指令
			PCodeList[PIndex].Kind = p_rdi;
			PIndex++;

			break;

		case t_gt:

			// 将 gt 指令转换成 P-代码
			// 产生一条 lda 指令
			PCodeList[PIndex].Kind = p_lda;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr3.Name);
			PIndex++;

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			if (TCodeList[TIndex].Addr2.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr2.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr2.Name);
			}
			PIndex++;

			PCodeList[PIndex].Kind = p_grt;
			PIndex++;

			PCodeList[PIndex].Kind = p_sto;
			PIndex++;

			break;

		case t_if_f:

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			// 产生一条 fjp 指令
			PCodeList[PIndex].Kind = p_fjp;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr2.Name);
			PIndex++;

			break;

		case t_asn:

			// 产生一条 lda 指令
			PCodeList[PIndex].Kind = p_lda;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr2.Name);
			PIndex++;

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			// 产生一条 sto 指令
			PCodeList[PIndex].Kind = p_sto;
			PIndex++;

			break;

		case t_lab:

			// 将 lab 指令转换成 P-代码
			PCodeList[PIndex].Kind = p_lab;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			PIndex++;

			break;

		case t_mul:

			// 产生一条 lda 指令
			PCodeList[PIndex].Kind = p_lda;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr3.Name);
			PIndex++;

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			if (TCodeList[TIndex].Addr2.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr2.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr2.Name);
			}
			PIndex++;

			// 产生一条 mpi 指令
			PCodeList[PIndex].Kind = p_mpi;
			PIndex++;

			// 产生一条 sto 指令
			PCodeList[PIndex].Kind = p_sto;
			PIndex++;

			break;

		case t_sub:

			// 将 sub 指令转换成 P-代码

			// 产生一条 lda 指令
			PCodeList[PIndex].Kind = p_lda;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr3.Name);
			PIndex++;

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			if (TCodeList[TIndex].Addr2.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr2.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr2.Name);
			}
			PIndex++;

			// 产生一条 sbi 指令
			PCodeList[PIndex].Kind = p_sbi;
			PIndex++;

			// 产生一条 sto 指令
			PCodeList[PIndex].Kind = p_sto;
			PIndex++;

			break;

		case t_eq:

			// 将 eq 指令转换成 P-代码

			// 产生一条 lda 指令
			PCodeList[PIndex].Kind = p_lda;
			PCodeList[PIndex].Addr.Kind = string;
			strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr3.Name);
			PIndex++;

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			if (TCodeList[TIndex].Addr2.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr2.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr2.Name);
			}
			PIndex++;

			// 产生一条 equ 指令
			PCodeList[PIndex].Kind = p_equ;
			PIndex++;

			// 产生一条 sto 指令
			PCodeList[PIndex].Kind = p_sto;
			PIndex++;

			break;

		case t_wri:

			// 将 wri 指令转换成 P-代码

			if (TCodeList[TIndex].Addr1.Kind == intconst)
			{
				// 产生一条 ldc 指令
				PCodeList[PIndex].Kind = p_ldc;
				PCodeList[PIndex].Addr.Kind = intconst;
				PCodeList[PIndex].Addr.Value = TCodeList[TIndex].Addr1.Value;
			}
			else
			{
				// 产生一条 lod 指令
				PCodeList[PIndex].Kind = p_lod;
				PCodeList[PIndex].Addr.Kind = string;
				strcpy(PCodeList[PIndex].Addr.Name, TCodeList[TIndex].Addr1.Name);
			}
			PIndex++;

			PCodeList[PIndex].Kind = p_wri;
			PIndex++;

			break;

		case t_halt:

			// 将 halt 指令转换成 P-代码

			PCodeList[PIndex].Kind = p_stp;
			PIndex++;

			break;
		}
	}
}

/*
功能：
	初始化三地址码列表（在执行流水线时调用）。
	
参数：
	pTCodeList -- 三地址码列表指针。
*/
void InitTCodeList(TCode *pTCodeList)
{
	for (int i = 0; i < MAX_CODE_COUNT; i++)
	{
		gets(TCodeArray[i]);
		int length = strlen(TCodeArray[i]);
		if (length == 0)
		{
			break;
		}
		char unitArr[7][64] = {};
		int k = 0, w = 0;
		for (int j = 0; j < 256; j++)
		{
			if (TCodeArray[i][j] == '\0')
			{
				break;
			}
			if (TCodeArray[i][j] == 32)
			{
				k++;
				w = 0;
				continue;
			}
			unitArr[k][w++] = TCodeArray[i][j];
		}

		char kind[64] = {0};
		strcpy(kind, unitArr[0]);
		if (strcmp(kind, "t_rd") == 0)
		{
			pTCodeList[i].Kind = t_rd;
		}
		else if (strcmp(kind, "t_gt") == 0)
		{
			pTCodeList[i].Kind = t_gt;
		}
		else if (strcmp(kind, "t_if_f") == 0)
		{
			pTCodeList[i].Kind = t_if_f;
		}
		else if (strcmp(kind, "t_asn") == 0)
		{
			pTCodeList[i].Kind = t_asn;
		}
		else if (strcmp(kind, "t_lab") == 0)
		{
			pTCodeList[i].Kind = t_lab;
		}
		else if (strcmp(kind, "t_mul") == 0)
		{
			pTCodeList[i].Kind = t_mul;
		}
		else if (strcmp(kind, "t_sub") == 0)
		{
			pTCodeList[i].Kind = t_sub;
		}
		else if (strcmp(kind, "t_eq") == 0)
		{
			pTCodeList[i].Kind = t_eq;
		}
		else if (strcmp(kind, "t_wri") == 0)
		{
			pTCodeList[i].Kind = t_wri;
		}
		else if (strcmp(kind, "t_halt") == 0)
		{
			pTCodeList[i].Kind = t_halt;
		}

		for (int j = 1; j < k; j += 2)
		{
			if (strcmp(unitArr[j], "string") == 0)
			{
				if (j == 1)
				{
					pTCodeList[i].Addr1.Kind = string;
					strcpy(pTCodeList[i].Addr1.Name, unitArr[j + 1]);
				}
				else if (j == 3)
				{
					pTCodeList[i].Addr2.Kind = string;
					strcpy(pTCodeList[i].Addr2.Name, unitArr[j + 1]);
				}
				else if (j == 5)
				{
					pTCodeList[i].Addr3.Kind = string;
					strcpy(pTCodeList[i].Addr3.Name, unitArr[j + 1]);
				}
			}
			else if (strcmp(unitArr[j], "intconst") == 0)
			{
				if (j == 1)
				{
					pTCodeList[i].Addr1.Kind = intconst;
					pTCodeList[i].Addr1.Value = atoi(unitArr[j + 1]);
				}
				else if (j == 3)
				{
					pTCodeList[i].Addr2.Kind = intconst;
					pTCodeList[i].Addr2.Value = atoi(unitArr[j + 1]);
				}
				else if (j == 5)
				{
					pTCodeList[i].Addr3.Kind = intconst;
					pTCodeList[i].Addr3.Value = atoi(unitArr[j + 1]);
				}
			}
		}
	}
}

/*
功能：
	输出三地址码列表。
	
参数：
	pCodeList -- P-代码列表指针。
*/
void OutputResult(PCode *PCodeList)
{

	for (int PIndex = 0; PCodeList[PIndex].Kind != 0; PIndex++)
	{
		switch (PCodeList[PIndex].Kind)
		{
		case p_lda:
			printf("lda%c%c%s\n", 32, 32, PCodeList[PIndex].Addr.Name);
			break;
		case p_rdi:
			printf("rdi\n");
			break;
		case p_lod:
			printf("lod%c%c%s\n", 32, 32, PCodeList[PIndex].Addr.Name);
			break;
		case p_ldc:
			printf("ldc%c%c%d\n", 32, 32, PCodeList[PIndex].Addr.Value);
			break;
		case p_grt:
			printf("grt\n");
			break;
		case p_fjp:
			printf("fjp%c%c%s\n", 32, 32, PCodeList[PIndex].Addr.Name);
			break;
		case p_sto:
			printf("sto\n");
			break;
		case p_lab:
			printf("lab%c%c%s\n", 32, 32, PCodeList[PIndex].Addr.Name);
			break;
		case p_mpi:
			printf("mpi\n");
			break;
		case p_sbi:
			printf("sbi\n");
			break;
		case p_equ:
			printf("equ\n");
			break;
		case p_wri:
			printf("wri%c%c%s\n", 32, 32, PCodeList[PIndex].Addr.Name);
			break;
		case p_stp:
			printf("stp\n");
			break;
		}
	}
}
