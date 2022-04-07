#include "SList.h"

SLTNode* BuySListNode(SLTDateType x)
{
	// 1M = 1024KB = 1024 * 1024 Byte
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLTNode*& phead, SLTDateType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		// 找到尾节点
		SLTNode* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SListPushFront(PSLTNode& phead, SLTDateType x)
{
	SLTNode* newnode = BuySListNode(x);

	newnode->next = phead;
	phead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	// 温柔的一点
	/*if (*pphead == NULL)
	{
	return;
	}*/

	// 粗暴一点
	assert(*pphead != NULL);

	// 1、一个节点
	// 2、两个及以上节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//SLTNode* prev = NULL;
		//SLTNode* tail = *pphead;
		////while (tail->next != NULL)
		//while (tail->next)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}

		//free(tail);
		//tail = NULL;
		//prev->next = NULL;

		SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);

	//if (*pphead == NULL)
	//	return;
	assert(*pphead != NULL);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}

// 在pos的后面插入，这个更适合，也更简单
void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	assert(pos);

	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	assert(pos);

	SLTNode* newnode = BuySListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		// 找到pos的前一个位置
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		/**pphead = pos->next;
		free(pos);*/
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		//pos = NULL;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	//next = NULL;
}


void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}