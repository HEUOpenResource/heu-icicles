#include "SymbolTable.h"
#include <stdlib.h>
#include <string.h>

SymboTable *pHead = NULL; // 符号表链表的头指针
int RefErrorCount = 0;	  // 符号引用失败计数器

char symbleTableContent[64][128];
int main()
{
	//
	// 构造符号表
	//
	CreateSymbolTable();

	//
	// 将符号表打印输出
	//
	OutputResult(pHead);
	FreeSymbolTable(pHead);

	return 0;
}

/*
功能：
	创建一个新的符号。
	
返回值：
	符号的指针。
*/
Symbol *NewSymbol()
{
	Symbol *pNewSymbol = (Symbol *)malloc(sizeof(Symbol));
	memset(pNewSymbol, 0, sizeof(Symbol));

	return pNewSymbol;
}

/*
功能：
	创建一个新的符号表。
	
返回值：
	符号表的指针。
*/
SymboTable *NewSymbolTable()
{
	SymboTable *pNewTable = (SymboTable *)malloc(sizeof(SymboTable));
	memset(pNewTable, 0, sizeof(SymboTable));

	return pNewTable;
}

/*
功能：
	在符号表链表的表头添加一个作用域。
*/
void PushScope()
{

	SymboTable *pSymboTable = NewSymbolTable();
	pSymboTable->pNext = pHead;
	pHead = pSymboTable;
}

/*
功能：
	将符号表链表中最内层的作用域设置成无效。
*/
void PopScope()
{
	SymboTable *pSymboTable = pHead;
	while (pSymboTable->Invalid == 1)
	{
		pSymboTable = pSymboTable->pNext;
	}
	pSymboTable->Invalid = 1;
}

/*
功能：
	对 Symbol 进行一次引用。
	
参数：
	pSymbolName -- 符号名称字符串指针。。
*/
void RefSymbol(const char *pSymbolName)
{
	int hash = Hush(pSymbolName);
	SymboTable *pSymboTable = pHead;
	while (pSymboTable)
	{
		if (pSymboTable->Invalid == 0)
		{
			Symbol *pSymbol = pSymboTable->Bucket[hash];
			while (pSymbol)
			{
				if (strcmp(pSymbol->SymbolName, pSymbolName) == 0)
				{
					pSymbol->RefCount++;
					return;
				}
				pSymbol = pSymbol->pNext;
			}
		}
		pSymboTable = pSymboTable->pNext;
	}
	RefErrorCount++;
	return;
}

/*
功能：
	向符号表中添加一个 Symbol。
	
参数：
	pSymbolName -- 符号名称字符串指针。
	pSymbolType -- 符号类型字符串指针。
*/
void AddSymbol(const char *pSymbolName, const char *pSymbolType)
{

	int hash = Hush(pSymbolName);
	Symbol *pSymbol = pHead->Bucket[hash];
	while (pSymbol)
	{
		if (strcmp(pSymbol->SymbolName, pSymbolName) == 0)
		{
			pSymbol->ClashCount++;
			return;
		}
		pSymbol = pSymbol->pNext;
	}
	Symbol *pNewSymbol = NewSymbol();
	pNewSymbol->pNext = pHead->Bucket[hash];
	pHead->Bucket[hash] = pNewSymbol;
	strcpy(pNewSymbol->SymbolName, pSymbolName);
	strcpy(pNewSymbol->SymbolType, pSymbolType);
}

/*
功能：
	求 Symbol 的哈希值。
	
参数：
	pSymbolName -- 符号名称字符串指针。
*/
int Hush(const char *pSymbolName)
{
	int HashValue = 0, i;

	for (i = 0; pSymbolName[i] != '\0'; i++)
	{
		HashValue = ((HashValue << 4) + pSymbolName[i]) % BUCKET_SIZE;
	}

	return HashValue;
}

/*
功能：
	创建符号表(在执行流水线时调用)。
*/
void CreateSymbolTable()
{
	for (int i = 0; i < 64; i++)
	{
		gets(symbleTableContent[i]);
		int length = strlen(symbleTableContent[i]);
		if (length == 0)
		{
			break;
		}
		if (strcmp(symbleTableContent[i], "pushscope") == 0)
		{
			PushScope();
		}
		else if (strcmp(symbleTableContent[i], "popscope") == 0)
		{
			PopScope();
		}
		else
		{
			int k = 0, m = 0;
			char symbolAR[2][128] = {0};
			for (int j = 0; j < 128; j++)
			{
				if (symbleTableContent[i][j] == 32)
				{
					if (symbleTableContent[i][j + 1] != 32 && symbleTableContent[i][j] != '\0')
					{
						k++;
						m = 0;
					}
					continue;
				}
				if (symbleTableContent[i][j] == '\0')
				{
					break;
				}
				symbolAR[k][m++] = symbleTableContent[i][j];
			}
			if (k == 0)
			{
				RefSymbol(symbolAR[0]);
			}
			else if (k == 1)
			{
				AddSymbol(symbolAR[0], symbolAR[1]);
			}
		}
	}
}

/*
功能：
	输出符号表。
*/
void OutputResult(SymboTable *pHead)
{
	printf("RefErrorCount: %d\n", RefErrorCount);
	printf("\nindex	\"barrel\"	ItemList(RefCount/ConflictCount)\n");
	for (int k = 0; k < 60; k++)
	{
		printf("%c", 45);
	}
	printf("\n");
	while (pHead != NULL)
	{
		printf("SymbolTableInvalid(Invalid = %d)\n", pHead->Invalid);
		for (int i = 0; i < BUCKET_SIZE; i++)
		{
			Symbol *curSymbol = pHead->Bucket[i];
			int j = 0;
			printf("%d ", i);
			while (curSymbol != NULL)
			{
				if (j == 0)
				{
					for (int k = 0; k < 25; k++)
					{
						printf("%c", 32);
					}
					j = 1;
				}
				printf("-->%s(%s)%d/%d ", curSymbol->SymbolName, curSymbol->SymbolType,
					   curSymbol->RefCount, curSymbol->ClashCount);
				curSymbol = curSymbol->pNext;
			}
			printf("\n");
		}
		pHead = pHead->pNext;
	}
}

void FreeSymbol(Symbol *pSymbol)
{
	if (pSymbol)
	{
		FreeSymbol(pSymbol->pNext);
		free(pSymbol);
	}
}

void FreeSymbolTable(SymboTable *pTable)
{
	if (pTable)
	{
		FreeSymbolTable(pTable->pNext);
		for (int i = 0; i < BUCKET_SIZE; ++i)
		{
			FreeSymbol(pTable->Bucket[i]);
		}
		free(pTable);
	}
}
