#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode, * PSLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode*& phead, SLTDateType x);
void SListPushFront(PSLTNode& phead, SLTDateType x);

void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDateType x);

void SListInsertAfter(SLTNode* pos, SLTDateType x);
// 在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode* pos);

void SListDestory(SLTNode** pphead);

// void SListInsert(SLTNode* phead, int pos, SLTDateType x);
// void SListErase(SLTNode** pphead, int pos);#pragma once
