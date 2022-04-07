#pragma once

namespace lxd
{
	static int rand;
	//int rang;
	struct ListNode
	{
		struct ListNode* next;
		int x;
	};
	void ListInit();
	void ListPushBack(struct ListNode* phead, int x);
}
