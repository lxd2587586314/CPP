#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDateType;

struct Stack
{
	int* a;
	int top;
	int capacity;

};

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDateType x);
//只有声明，没有定义 链接错误