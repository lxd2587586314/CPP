#pragma once

class Stack
{
public:
	void Init();
	void Push(int x);
	// ...
//private:
	int* _a;
	int _top;
	int _capacity;
};