# Lesson00---C++入门

1. C++关键字 

2.  命名空间 

3. C++输入&输出 

4. 缺省参数

5.  函数重载 

6. 引用 

7. 内联函数

8.  auto关键字(C++11) 

9. 基于范围的for循环(C++11) 

10.  指针空值---nullptr(C++11)

​    

## 1.C++关键字(C++98)

![image-20220111124449648](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220111124449648.png)

## 2.命名空间 

在C/C++中，变量、函数和后面要学到的类都是大量存在的，这些变量、函数和类的名称将都存在于全局作 用域中，可能会导致很多冲突。使用命名空间的目的是对标识符的名称进行本地化，以避免命名冲突或名字 污染，namespace关键字的出现就是针对这种问题的。

![image-20220111125927961](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220111125927961.png)

### 2.1 命名空间定义和使用

![image-20220111131454019](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220111131454019.png)

==相当于隔离变量，一件隐身衣，依然存在只是编译器寻找不到==

~~~cpp
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

~~~

不加static的变量从其他cpp文件和test.cpp链接就会报错

![image-20220111181721759](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220111181721759.png)

定义命名空间，需要使用到namespace关键字，后面跟命名空间的名字，然后接一对{}即可，{}中即为命名 空间的成员。

~~~c
//1. 普通的命名空间
namespace N1 // N1为命名空间的名称
{
 	// 命名空间中的内容，既可以定义变量/函数/类型
 	int a;
 	int Add(int left, int right)
 	{
 		return left + right;
 	}
}
//2. 命名空间可以嵌套
namespace N2
{
 	int a;
 	int b;
 	int Add(int left, int right)
 	{
 		return left + right;
 	}
 
 	namespace N3
 	{
 		int c;
 		int d;
 		int Sub(int left, int right)
 		{
			 return left - right;
		}
	 }
}
//3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
namespace N1
{
	 int Mul(int left, int right)
 	{
		 return left * right;
 	}
}
~~~

![image-20220111193753232](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220111193753232.png)

平时练习为了方便，就将c++的库全部展开

![image-20220111193859066](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220111193859066.png)

