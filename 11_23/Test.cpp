#include <stdio.h>
#include <stdlib.h>
#include "List.h"
//#include "List.h"
// CPP -> C plus plus

// 命名冲突问题
// 1、我们自己定义的变量、函数可能跟库里面重名冲突
// 2、进入公司项目组以后，做的项目通常比较大。多人协作，两个同事写的代码，命名冲突。
// C语言没有办法很好的解决这个问题
// CPP提出一个新语法，命名空间

//// 定义了一个叫bit的命名空间 -- 域
//namespace hang
//{
//	// 他们还是全局变量，放到静态区的
//	int rand = 2;
//	int a = 1;
//}
////c语言不支持namespace
//namespace lxd
//{
//	int rand = 0;
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//
//}
//int a = 1;
//int rand = 0;
//int main()
//{
//	printf("hello world\n");
//	printf("%d\n", rand);
//	printf("%d\n", lxd::rand);//lxd命名空间里
//	printf("%d\n", hang::rand);
//	
//	int a = 3;
//	printf("%d\n", a);//优先局部 近者优先
//	printf("%d\n", ::a); //空白代表全局
//	return 0;
//}
// 
//namespace lxd
//{
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//namespace hang
//{
//	// 1、命名空间中可以定义变量/函数/类型
//	//int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right + 10;
//	}
//}
//
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right + 10;
//	}
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right + 10;
//		}
//	}
//}

//int main()
//{
//	struct lxd::Node node;
//	lxd::Add(1, 2);
//	hang::Add(1, 2);
//	N1::N2::Sub(1, 2);
//	struct lxd::ListNode In;
//	lxd::ListInit();
//
//}
//// 把整个命名空间展开 -- 展开到全局了
//using namespace lxd;
//
//// 单独展开某一个，其他不展开
//using lxd::ListNode;
//
//int main()
//{
//	struct ListNode In;
//	lxd::ListInit();
//	printf("%d", lxd::rand);
//}
//#include <iostream>
//using namespace std;  // C++库的实现定义在一个叫std的命名空间中
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}
//#include <iostream>
////using namespace std;  // C++库的实现定义在一个叫std的命名空间中
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//	return 0;
//}
// 
#include <iostream>
using namespace std;
//// 常用的展开
//using std::cout;
//using std::endl;
// 
//int main()
//{
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//
//	return 0;
//}

int main()
{
	cout << "hello world" << endl;
	cout << "hello world" << '\n';
	cout << "hello world\n";
	printf("hello world\n");
	int a = 0;
	double d = 3.14;

	cout << a <<' '<< d << endl;
 //<<流插入运算符
	cin >> a >> d;
 //<<流提取运算符
	printf("%d %lf\n", a, d);
	cout << a << ' ' << d << endl;
	return 0;
}
// c语言可以和c++混着用
//cout比printf慢就相当于前置++比后置++快 对于早期的计算机或许有这样的差异 对于现在
//来说已经没有什么差异