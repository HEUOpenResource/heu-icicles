#ifndef T2P_H_
#define T2P_H_

//
// 在此处包含 C 标准库头文件
//

#include <stdio.h>

//
// 在此处包含其他头文件
//


//
// 在此处定义数据结构
//

#define MAX_STR_LENGTH	64
#define MAX_CODE_COUNT	64

// 地址类型
typedef enum _AddrKind
{
	empty,		// 空
	intconst,	// 整数常量
	string		// 字符串
}AddrKind;

// 地址
typedef struct _Address
{
	AddrKind Kind; 				// 地址的类型。这个域是一个枚举类型
	int Value;	   				// 地址的值。地址类型为整数常量时，这个域有效
	char Name[MAX_STR_LENGTH]; 	// 地址的值。地址类型为字符串时，这个域有效
}Address;

// 三地址码指令类型
typedef enum _TOpKind
{
	t_rd = 1, // 注意，从 1 开始
	t_gt,
	t_if_f,
	t_asn,
	t_lab,
	t_mul,
	t_sub,
	t_eq,
	t_wri,
	t_halt
}TOpKind;

// 三地址码
typedef struct _TCode
{
	TOpKind Kind;		// 三地址码指令类型
	Address Addr1, Addr2, Addr3; // 三个地址
}TCode;

// P-代码指令类型
typedef enum _POpKind
{
	p_lda = 1, // 注意，从 1 开始
	p_rdi,
	p_lod,
	p_ldc,
	p_grt,
	p_fjp,
	p_sto,
	p_lab,
	p_mpi,
	p_sbi,
	p_equ,
	p_wri,
	p_stp
}POpKind;

// P-代码
typedef struct _PCode
{
	POpKind Kind; // P-代码指令类型
	Address Addr; // 地址
}PCode;

//
// 在此处声明函数
//

void T2P(TCode* TCodeList, PCode* PCodeList);
void InitTCodeList(TCode* pTCodeList);
void InitTCodeList_CI(TCode* pTCodeList);
void OutputResult(PCode* PCodeList);

//
// 在此声明全局变量
//

#endif // T2P_H_
