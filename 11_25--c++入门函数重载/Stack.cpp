#include "Stack.h"
void StackInit(struct Stack* ps, int capacity)
{
	ps->a = (int*)malloc(sizeof(int) * capacity);
	// 
	ps->top = 0;
	ps->capacity = capacity;
}

void StackPush(struct Stack* ps, int x)
{
	// ...
}