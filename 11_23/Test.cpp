#include <stdio.h>
#include <stdlib.h>
#include "List.h"
//#include "List.h"
// CPP -> C plus plus

// ������ͻ����
// 1�������Լ�����ı������������ܸ�������������ͻ
// 2�����빫˾��Ŀ���Ժ�������Ŀͨ���Ƚϴ󡣶���Э��������ͬ��д�Ĵ��룬������ͻ��
// C����û�а취�ܺõĽ���������
// CPP���һ�����﷨�������ռ�

//// ������һ����bit�������ռ� -- ��
//namespace hang
//{
//	// ���ǻ���ȫ�ֱ������ŵ���̬����
//	int rand = 2;
//	int a = 1;
//}
////c���Բ�֧��namespace
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
//	printf("%d\n", lxd::rand);//lxd�����ռ���
//	printf("%d\n", hang::rand);
//	
//	int a = 3;
//	printf("%d\n", a);//���Ⱦֲ� ��������
//	printf("%d\n", ::a); //�հ״���ȫ��
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
//	// 1�������ռ��п��Զ������/����/����
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
//// �����������ռ�չ�� -- չ����ȫ����
//using namespace lxd;
//
//// ����չ��ĳһ����������չ��
//using lxd::ListNode;
//
//int main()
//{
//	struct ListNode In;
//	lxd::ListInit();
//	printf("%d", lxd::rand);
//}
//#include <iostream>
//using namespace std;  // C++���ʵ�ֶ�����һ����std�������ռ���
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}
//#include <iostream>
////using namespace std;  // C++���ʵ�ֶ�����һ����std�������ռ���
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
//// ���õ�չ��
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
 //<<�����������
	cin >> a >> d;
 //<<����ȡ�����
	printf("%d %lf\n", a, d);
	cout << a << ' ' << d << endl;
	return 0;
}
// c���Կ��Ժ�c++������
//cout��printf�����൱��ǰ��++�Ⱥ���++�� �������ڵļ���������������Ĳ��� ��������
//��˵�Ѿ�û��ʲô����