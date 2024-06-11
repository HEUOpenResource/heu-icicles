#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_


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
#define BUCKET_SIZE		5	// 选择一个素数作为桶大小。

typedef struct _Symbol
{
	char SymbolName[MAX_STR_LENGTH]; // 符号名称
	char SymbolType[MAX_STR_LENGTH]; // 符号类型
	int ClashCount;					 // 冲突次数
	int RefCount;					 // 引用次数
	struct _Symbol* pNext;			 // 指向下一个 Symbol
}Symbol;

typedef struct _SymbolTable
{
	Symbol* Bucket[BUCKET_SIZE]; // 杂凑表(桶)
	int Invalid;				 // 作用域是否无效的标志。1 表示无效，0 表示有效
	struct _SymbolTable* pNext;	 // 指向下一个 SymbolTable
}SymboTable;

//
// 在此处声明函数
//

Symbol* NewSymbol();
SymboTable* NewSymbolTable();
void PushScope();
void PopScope();
void RefSymbol(const char* pSymbolName);
void AddSymbol(const char* pSymbolName, const char* pSymbolType);
int Hush(const char* pSymbolName);
void CreateSymbolTable();
void CreateSymbolTable_CI();
void OutputResult();

//
// 在此声明全局变量
//

extern SymboTable* pHead;
extern int RefErrorCount;

#endif // SYMBOL_TABLE_H_
