#include "Stack.h"

void Stack::Init() //寻找_a 先在局部 - 全局 - 类域
{
	_a = nullptr;
	_top = _capacity = 0;
}