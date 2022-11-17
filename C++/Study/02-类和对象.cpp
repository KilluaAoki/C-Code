#include <iostream>

/*
	类和对象
		01.面向过程和面向对象的初步认识
		02.类的引入和定义
		03.类的访问限定符及封装
		04.类的作用域
		05.类的实例化和对象模型
		06."this"指针
		07.类的六个默认成员函数
		08.构造函数
		09.析构函数
		10.拷贝构造函数
		11.拷贝赋值运算符
		12."const"成员函数
		13.取地址及"const"取地址操作符重载
		14.再谈构造函数
		15."static"成员
		16.友元
		17.内部类
		18.匿名对象
		19.拷贝对象时的一些编译器优化
		20.再次理解封装
*/

/**
	面向过程和面向对象的初步认识
		1.C与C++
			a.C是面向过程的语言，其注重的是过程，即分析解决问题所需的步骤，从而通过函数逐步解决问题。
			b.C++严格意义上是面向过程与面向对象混合型语言，可理解为面向对象的语言，其注重的是对象，即分析解决问题所需的对象，从而通过对象之间的交互来解决问题。
		2.思维上的面向过程和面向对象
			a.无论是面向过程还是面向对象，都是一种思维方式，即分析解决问题所需的步骤或对象，从而通过函数或对象之间的交互来解决问题。
			b.汇编语言是面向机器的语言，也可说是面向细节的语言，其需要通过一条条指令操作来解决问题，是人脑模拟计算机的一种思维方式。
		3.语言上的面向过程和面向对象
			a.面向过程和面向对象并不决定于语言，而是取决于思维，是一种编程思想，而语言是可以实现这种思想的工具。
			b.C语言并非不可以实现面向对象的思想，仅是在面向对象方面，C语言提供的语法支持较为薄弱，但C语言的结构体、函数指针可以实现面向对象的思想，事实上，使用C语言实现的多数编程框架、库、驱动等都是具有面向对象思想的。
			c.C++在语法层面上提供了对面向对象编程更好的支持，能让使用它的人更加优雅的面向对象编程。
		4.面向对象的三大特性：封装、继承、多态。(封装将在本章的"03"小节介绍，而其它特性将会在之后的章节中介绍)(并非仅有这三大特性)
*/

/**
	类的引入和定义
		1.C++对C语言结构体的升级
			a.C++升级了C语言的结构体，其兼容了C语言中结构体的所有用法，并使其具有了面向对象的特征，称之为类。
			b.C语言中的结构体只允许有变量(数据成员)，不能有函数(函数成员)，而C++中的结构体允许有变量(数据成员)和函数(函数成员)。
			c.C++中将结构体的名称称之为类名，将结构体中的数据成员称之为成员变量或类的属性，将结构体中的函数成员称之为成员函数或类的方法。
			d.对象是指类的实例，使用已经定义的类去说明它的实例变量，即通过类创建的变量，称之为对象。
			e.一个对象是类的一个实例，类中具有的成员变量和成员函数，对于对象来说也是对象的属性和对象的方法。
			f.C++使用类实例化对象时是可以直接使用类名加对象名实例化的，而C语言使用结构体类型定义结构体变量时，必须在变量名前加上"struct"关键词(除非使用"typedef"关键词)。
		2."class"关键词
			a.使用"class"关键词定义类的格式如下：
				class 类头名
				{
					成员说明(类体)
				};
			b.除了默认成员访问和默认基类访问之外(将在本章的"03"小节中介绍)，可以认为"class"关键词与"struct"关键词在类的声明上是等同的。
			c.C++11前，类体中不可声明的同时给予缺省值于非静态数据成员(除非是常量静态数据成员)，而C++11后，非静态数据成员可以在类体中声明的同时给予缺省值，但其依旧是声明而不是定义。
			d.类体中的函数成员的定义实际上也是一种声明，定义是包含了函数体的实现，而声明只是声明了函数的原型，而不包含函数体的实现。(不同于数据成员)
		3.类的两种定义方式
			a.在类体中声明成员变量和直接定义成员函数。
			b.在类体中声明静态成员变量和成员函数，然后在类体外定义静态成员变量和成员函数。(暂不考虑静态成员函数)(声明和定义分离的一种体现)
				a'.类体中并不能直接定义静态成员变量，因为定义需要分配内存，静态成员变量是随着类的，静态成员变量属于类级别高于普通成员变量的对象级别，不能随着对象的创建再申请静态成员变量的内存，所以需要单独在类的外部定义。
				b'.在类体外定义静态成员变量或成员函数时，需在静态成员变量定义的变量名或成员函数定义的函数名前加上类名和作用域解析运算符"::"。
		4."struct"关键词和"class"关键词的编程规范(不一定遵守)
			a.通常情况下仅当只有数据成员时使用"struct"关键词，其它一概使用"class"关键词，因为这两个关键词的含义几乎相同，所以我们为这两个关键字添加我们自己的语义理解，以便为定义的数据类型选择合适的关键字。
			b."class"类体中的成员变量命名是具有多种不同的命名规范的，通常会在成员变量名前加上"m_"前缀或直接以下划线结尾，以区别于普通的变量名。
			c.结构体数据成员与普通变量命名规范一致即可。
*/

////类的引入和定义示例一：使用"struct"关键词定义类。
//struct Rectangle
//{
//	//成员变量
//	int length;
//	int width;
//
//	//成员函数(不同于C语言中的结构体，C++中的结构体允许有函数成员)
//	int Area()
//	{
//		return length * width;
//	}
//};
//
//int main()
//{
//	Rectangle rect;//直接可以使用类名加对象名实例化对象"rect"。
//	rect.length = 10;//通过对象名访问成员变量。
//	rect.width = 20;//通过对象名访问成员变量。
//	std::cout << "Area = " << rect.Area() << std::endl;//通过对象名访问成员函数。
//	return 0;
//}

////类的引入和定义示例二：使用"class"关键词定义类。
//class Rectangle
//{
//public://公有成员访问权限，将在本章的"03"小节中介绍。
//	//成员变量
//	int length;
//	int width;
//
//	//成员函数
//	int Area()
//	{
//		return length * width;
//	}
//};
//
//int main()
//{
//	Rectangle rect;
//	rect.length = 10;
//	rect.width = 20;
//	std::cout << "Area = " << rect.Area() << std::endl;
//	return 0;
//}

////类的引入和定义示例三：在类体外定义的静态成员变量和成员函数。
//class Test
//{
//public:
//	//成员变量
//	int m_a;//声明成员变量，属于对象级别。
//	static int m_b;//声明静态成员变量，属于类级别。
//
//	//成员函数
//	void Func();//声明成员函数，属于对象级别。
//};
//
//int Test::m_b = 10;//在类体外定义已在类中声明的静态成员变量。
//
//void Test::Func()//在类体外定义已在类中声明的成员函数。
//{
//	std::cout << "Func()" << std::endl;
//}
//
//int main()
//{
//	Test test;
//
//	test.m_a = 10;//通过对象名访问成员变量。
//
//	test.Func();//通过对象名访问成员函数。
//
//	std::cout << "test.m_a = " << test.m_a << std::endl;//通过对象名访问成员变量。
//
//	std::cout << "Test::m_b = " << Test::m_b << std::endl;//通过类名访问静态成员变量。
//
//	return 0;
//}

/**
	类的访问限定符及封装
		1.访问说明符：又称为访问限定符，在类的成员说明中定义其后继成员的可访问性。
			a.C++中的访问说明符有"public"、"protected"和"private"三种。
				a'."public"：公有访问权限，该访问说明符之后的各个成员具有公开成员访问，可以在类的内部和外部被访问。
				b'."private"：私有访问权限，该访问说明符之后的各个成员具有私有成员访问，成员在类的内部可以被访问，外部不可以被访问。
				c'."protected"：保护访问权限，该访问说明符之后的各个成员具有保护成员访问，类似于私有访问权限，类外部不可以被访问，但是成员在基类的派生类中可以被访问。(当期阶段暂不讨论)
			b.访问说明符说明
				a'.访问说明符的作用范围是从其出现的位置开始，直到下一个访问说明符出现的位置为止，若没有下一个访问说明符，则到类体结束为止。
				b'.类中的所有成员都拥有对类所能访问的所有名字的访问权。(包括在类中声明的成员函数，并在类外定义的成员函数)
				c'.以"class"关键词定义的类默认的访问说明符为"private"，而以"struct"关键词定义的类默认的访问说明符为"public"(为了兼容C语言)。
				d'.在程序的任何位置使用成员的名字时都会检查其访问，而且如果它不满足访问规则，那么程序不能编译。
		2.封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行交互。
			a.C++中可以通过类将数据和操作数据的方法进行有机结合，并且可以通过访问说明符来隐藏对象内部实现细节，并控制哪些方法可以在类的外部直接被使用，从而实现封装。
*/

////类的访问限定符及封装示例一：公开成员访问，即访问说明符"public"的使用。
//class S
//{
//public://从这里开始，直到下一个访问说明符出现的位置为止或者到类体结束为止，类中的成员都具有公开成员访问。
//	int n = 10;
//
//	enum E
//	{
//		A, B, C
//	};
//
//	struct U
//	{
//	};
//};//类体结束，变量"n"、枚举类型"E"、枚举类型"E"的所有成员、结构体类型"U"都具有公开成员访问。
//
//int main()
//{
//	S s;
//
//	std::cout << "s.n = " << s.n << std::endl;//"s.n"可以在类的外部被访问。
//
//	std::cout << "S::E::A = " << S::E::A << std::endl;//枚举类型"E"的所有成员可以在类的外部被访问。(只列举其中一个成员)
//
//	S::U u;//结构体类型"U"可以在类的外部被访问。
//
//	return 0;
//}

////类的访问限定符及封装示例二：私有访问权限，即访问说明符"private"的使用。
//class S
//{
//private:
//	int n = 10;
//};
//
//int main()
//{
//	S s;
//	//std::cout << "s.n = " << s.n << std::endl;//错误，"s.n"不能在类的外部被访问，因为它具有私有访问权限。
//	return 0;
//}

/**
	类的作用域：在类中声明的名称的作用域是整个类，作用域为整个类的名称只在该类中是已知的，在类外是不可知的。
		1.与类的作用域有关的三个运算符
			a.作用域解析运算符"::"：如果此运算符左侧的查找结果是类名，那么右侧的名字会在该类的作用域中进行查找(可能找到该类或它的基类的成员的声明)，具有例外情况。
			b.成员访问运算符"."：用于对象，提供对它的对象操作数的数据成员或成员函数的访问。
			c.成员指针访问运算符"->"：用于指针，提供对它的指针操作数所指向的类的数据成员或成员函数的访问。
		2.类的成员名存在的四种语境(派生类暂不考虑)
			a.在其自身的类作用域之中。
			b.在对其类的对象(表达式)运用成员访问运算符"."之后。
			c.在对其指向类的对象的指针(表达式)运用成员指针访问运算符"->"之后。
			d.在对其类的名字运用作用域解析运算符"::"之后。
*/

////类的作用域示例：类的成员名存在的四种语境。
//class S
//{
//public:
//	int n = 10;//在其自身的类作用域之中，此类往后成员不再赘述。
//	static int m;
//
//	void f();
//};
//
//int S::m = 20;//在对其类的名字运用作用域解析运算符"::"之后。
//
//void S::f()//在对其类的名字运用作用域解析运算符"::"之后。
//{
//	std::cout << "f()" << std::endl;
//}
//
//int main()
//{
//	S s;
//	S* ps = &s;
//
//	std::cout << "s.n = " << s.n << std::endl;//在对其类的对象(表达式)运用成员访问运算符"."之后。
//	std::cout << "S::m = " << S::m << std::endl;//在对其类的名字运用作用域解析运算符"::"之后。
//	std::cout << "ps->n = " << ps->n << std::endl;//在对其指向类的对象的指针(表达式)运用成员指针访问运算符"->"之后。
//
//	s.f();//在对其类的对象(表达式)运用成员访问运算符"."之后。
//	ps->f();//在对其指向类的对象的指针(表达式)运用成员指针访问运算符"->"之后。
//
//	return 0;
//}

/**
	类的实例化和对象模型
		1.类的实例化：类的实例化是指将类的定义转换为类的对象的过程。
			a.一个类可以实例化出多个对象。
			b.类实例化出的对象，占据着实际的内存空间(栈区或堆区)，存储着类的成员变量。
		2.类的内存分配(对象模型)
			a.定义类时，并不会实际分配内存，只有在实例化对象时，才会分配内存。(不包括类的静态成员)
			b.当类中含有一个或多个静态成员变量声明时，它们将在其定义时于内存中的静态区分配内存，并且此类实例化出的所有对象都共享这些静态成员变量。
			c.类中所定义的函数(包括类体外定义的函数)(不论是静态或是非静态)，它们都存储在内存的代码段中，计算类的大小时，不包括函数的大小。
		3.计算类的大小：实际上是计算使用类所实例化出的对象的所占空间大小。
			a.使用"sizeof"运算符可以计算类或类的对象的大小
				a'.当应用于类类型时，结果是该类的完整对象所占据的字节数，实际上就是计算该类中所有成员变量所占据的字节数(不包括静态成员变量)。
				b'."sizeof"运算符的结果始终非零，即使应用于空类。
			b.空类的大小通常为一个字节(由编译器所决定的)，其并不存储有效数据，而是作为占位，标记着对象的存在，以区分实例化后的对象。
			c.与C语言一样，C++中的类也涉及到内存对齐的规则，这里不再赘述。
*/

////类的实例化和对象模型示例一：共享的静态成员变量。
//class S
//{
//public:
//	static int m;
//};
//
//int S::m = 0;
//
//int main()
//{
//	S s1, s2;
//
//	s1.m = 1;
//	s2.m = 2;
//
//	std::cout << "s1.m = " << s1.m << "\n"
//			  << "s2.m = " << s2.m << "\n"
//			  << "S::m = " << S::m << std::endl;//发现三者的值都是"2"，说明静态成员变量是共享的。
//
//	return 0;
//}

////类的实例化和对象模型示例二：计算类的大小。
//class A
//{
//public:
//	void PrintA()
//	{
//		std::cout << "PrintA()" << std::endl;
//	}
//
//private:
//	char _a;
//	static int _b;
//};
//
//int A::_b = 0;
//
//int main()
//{
//	A a;
//	std::cout << "sizeof(A) = " << sizeof(A) << std::endl;//计算的结果不包含静态成员变量以及函数，结果为：1。
//	std::cout << "sizeof(a) = " << sizeof(a) << std::endl;//发现结果为：1，与上面的结果一致。
//	return 0;
//}

////类的实例化和对象模型示例三：计算空类的大小。
//class A1//类中既有成员变量，又有成员函数。
//{
//public:
//	void f1()
//	{
//	}
//
//private:
//	int _a;
//};
//
//class A2//类中只有成员函数。
//{
//public:
//	void f2()
//	{
//	}
//};
//
//class A3//空类。
//{
//};
//
//int main()
//{
//	std::cout << "sizeof(A1) = " << sizeof(A1) << std::endl;//此类体中既有成员变量，又有成员函数，计算的是成员变量的大小，结果为：4。
//	std::cout << "sizeof(A2) = " << sizeof(A2) << std::endl;//此类体中只有成员函数，等同于空类，结果为：1。
//	std::cout << "sizeof(A3) = " << sizeof(A3) << std::endl;//此类为空类，结果为：1。
//
//	A3 a1, a2;
//	std::cout << "&a1 = " << &a1 << " " << "&a2 = " << &a2 << std::endl;//发现一个空类实例化出的两个对象的地址是不相同的。
//
//	return 0;
//}

////类的实例化和对象模型示例四：计算类的大小(探究类的内存对齐)。
//class A
//{
//public:
//	int _a;
//	char _b;
//	int _c;
//};
//
//int main()
//{
//	//获取编译器的默认对齐数
//	std::cout << "默认对齐数：" << alignof(A) << std::endl;
//
//	//计算类的大小
//	std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
//	//类"A"第一个成员变量类型为"int"，大小为"4"个字节，存放在偏移量为"0"的地址处。
//	//类"A"第二个成员变量类型为"char"，大小为"1"个字节，存放在对齐数(取成员类型大小与默认对齐数的较小值)为"1"的整数倍的地址处，即偏移量为"4"的地址处。
//	//类"A"第三个成员变量类型为"int"，大小为"1"个字节，存放在对齐数(取成员类型大小与默认对齐数的较小值)为"4"的整数倍的地址处，即偏移量为"8"的地址处。
//	//类"A"的总大小，是当前已存放的总内存大小("12")扩展到每个成员的对齐数的最大对齐数的整数倍，也就是对齐数"4"的整数倍，即大小为"12"字节。
//
//	//计算类中的所有成员变量的偏移量
//	std::cout << "offsetof(A, _a) = " << offsetof(A, _a) << "\n"
//			  << "offsetof(A, _b) = " << offsetof(A, _b) << "\n"
//			  << "offsetof(A, _c) = " << offsetof(A, _c) << std::endl;
//
//	return 0;
//}

/**
	"this"指针：纯右值(与右值相同)表达式，它的值是隐式对象形参(在它之上调用非静态成员函数的对象)的地址。
		1.不同对象调用同一个成员函数，编译器如何区分？
			a.编译器会在每个非静态成员函数的形参列表中加上一个隐式的形参，这个形参就是"this"指针，它的值就是调用该成员函数的对象的地址，所以在成员函数中可以通过"this"指针来区分不同对象。
			b.成员函数函数体中对对象的属性的访问或是操作，都是通过"this"指针隐式访问该对象，从而完成对对象的属性进行访问或是操作。
		2."this"指针的特性
			a.在类的成员函数中，"this"指针是指向类的指针，即"类名*"，但"this"指针是不能改变其指向的对象的，故"this"指针的类型是"类名* const"。
			b."this"指针在C++的不同标准下具有不同的出现语境，详见文档。
			c.对象中并不会存储"this"指针，其并不是随着对象的实例化而存在的，而是随着成员函数的调用，作为成员函数的形参接收对象的地址，所以其存在于栈中。
			d.通常访问对象的成员变量时，编译器会隐式的使用"this"指针，也可以显式的使用"this"指针，但是显式的使用"this"指针时，必须要加上"->"运算符，并且左操作数为"this"指针，右操作数为成员变量。
		3.文档：https://zh.cppreference.com/w/cpp/language/this。
*/

////"this"指针示例一：隐含的"this"指针。
//class T
//{
//public:
//	void Print()//其成员函数的形参列表具有一个隐式的形参，即"this"指针。
//	{
//		std::cout << "this = " << this << std::endl;//通过显式的"this"指针打印其存放的值。
//	}
//
//	void foo()
//	{
//		x = 1000;//此行语句等同于"this->x = 1000;"。
//		std::cout << "x = " << x << std::endl;
//		this->x = 5;//显式的使用"this"指针访问成员变量。
//		std::cout << "this->x = " << this->x << std::endl;
//	}
//
//	void foo(int x)//此时的形参"x"与成员变量"x"同名，需要显式的使用"this"指针才能够表示成员变量，否则会被认为是形参。
//	{
//		x = 10;//此时修改的"x"是形参"x"，而不是成员变量"x"。
//		std::cout << "x(形参) = " << x << std::endl;//输出形参"x"的值。
//		std::cout << "this->x = " << this->x << std::endl;//输出成员变量"x"的值。
//	}
//
//private:
//	int x = 0;
//};
//
//int main()
//{
//	T t;
//
//	printf("Print()：\n");
//	std::cout << "&t = " << &t << std::endl;
//	t.Print();//可以发现，"this"指针的值就是调用该成员函数的对象的地址。
//
//	printf("\nfoo()：\n");
//	t.foo();
//
//	printf("\nfoo(int x)：\n");
//	t.foo(0);
//
//	return 0;
//}

////"this"指针示例二：判别以下程序分别会出现什么错误。
//class A
//{
//public:
//	void PrintA()
//	{
//		std::cout << "PrintA()" << std::endl;
//	}
//
//	void PrintB()
//	{
//		std::cout << _a << std::endl;//实际上为"this->_a"，若此时"this"指针的值为空，则会出现空指针解引用的错误(段错误)。
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();//"p->PrintA()"不发生解引用，因为成员函数的地址并不在对象中；此处将"nullptr"作为实参传递给了成员函数中的"this"指针，程序正常运行。
//	p->PrintB();//"p->PrintA()"依旧不发生解引用，但是"PrintB()"函数中访问了成员变量(进行了解引用)，因此会发生段错误。
//	return 0;
//}

/**
	类的六个默认成员函数
		1.类的六个默认成员函数分别为：默认构造函数、默认拷贝构造函数、默认移动构造函数(C++11)、默认拷贝赋值运算符、默认移动赋值运算符(C++11)、默认析构函数。
			a.在一个什么都没有的类中，将其称之为空类，而此时编译器会为其隐式生成六个默认成员函数，注意编译器也可能无法生成其中的某些默认成员函数。
			b.默认移动构造函数和默认移动赋值运算符是C++11中新增的，用于移动语义。
		2.平凡与非平凡的特殊成员函数(拓展以便于阅读文档)
			a.平凡意味着这些特殊的成员函数用很朴素的方式完成它们的工作，而朴素的方式这个说法对于不同的特殊成员函数有不同的含义。
			b.非平凡意味着是由自己定义的成员函数，即使它什么也不做，也不是平凡的，这就意味着平凡实际上是由编译器隐式定义的。
			c.由编译器隐式生成的特殊成员函数是平凡的，而由用户自己显式定义的特殊成员函数是非平凡的。
*/

/**
	构造函数：构造函数是类的一种特殊的非静态成员函数，用于初始化该类类型的对象。
		1.构造函数的语法格式
			a.构造函数的名字与类名相同，且没有返回值。
			b.构造函数使用成员函数声明符声明，并且其具有多种形式，此小节只演示常见的构造函数，其他形式的构造函数请参考文档。
		2.构造函数的特性
			a.默认构造函数是不需要实参就能调用的构造函数(以空的或为每个形参提供默认实参的参数列表定义)。
			b.当类示例化一个对象时，构造函数将被自动调用，用于初始化该对象，保证了对象的每个数据成员都有一个合适的初始值，并在只在对象整个生命周期内调用一次。
			c.构造函数是可以重载的，并且也可以配合缺省参数使用，但注意只能有一个默认构造函数，若是一个无参的构造函数和全缺省的构造函数同时存在，则编译器会报错(二义性问题)。
			d.当类没有显式定义任何默认构造函数时，编译器会自动为其隐式生成一个默认构造函数，而如果当类中显式定义了默认构造函数时，编译器将不再为其隐式生成默认构造函数。
			e.由编译器隐式生成的默认构造函数并不会对其基本类型(内置类型)的成员变量进行操作，而对于自定义类型的成员变量，编译器会调用属于它类中的默认构造函数(若此成员变量的类中依旧没有显式定义默认构造函数，则编译器依旧生成默认构造函数，以此往复)。
			f.在本章的"02.类的引入和定义-2.-c."中我们提到了在类中给成员变量给初始值的方法，编译器在隐式生成默认构造函数中，会使用此值给此成员变量赋初值，但若是显式定义了默认构造函数则会使用此默认构造函数中的值给内置类型的成员变量赋初值(若无则自动添加)。
		3.文档
			a.https://zh.cppreference.com/w/cpp/language/constructor。(构造函数与成员初始化列表)
			b.https://zh.cppreference.com/w/cpp/language/default_constructor。(默认构造函数)
*/

////构造函数示例一：在类中显式定义构造函数。
//class A
//{
//public:
//	A(int a, int b)
//	{
//		this->a = a;//为更容易区分形参和成员变量，这里使用this指针。
//		this->b = b;
//	}
//
//	void Print()
//	{
//		std::cout << "a = " << a << ", b = " << b << std::endl;
//	}
//
//private:
//	int a;
//	int b;
//};
//
//int main()
//{
//	A a(1, 2);//构造函数能够初始化对象的数据成员，此时是显式调用构造函数。
//	a.Print();//可以发现对象"a"的数据成员已经被初始化。
//	return 0;
//}

////构造函数示例二：无参和带参的构造函数重载。
//class Date
//{
//public:
//	//无参构造函数
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//	//有参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		std::cout << _year << "-" << _month << "-" << _day << std::endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;//此时会直接调用无参构造函数(自动)。
//	Date d2(2002, 8, 30);//此时会直接调用带参的构造函数。
//	//Date d3();//错误，因为这种写法是函数声明(空括号解释为函数声明)，而不是调用无参的构造函数。
//
//	d1.Print();//可以发现对象"d1"的数据成员都已经被无参构造函数初始化为"0"。
//	d2.Print();//可以发现对象"d2"的数据成员都已经被带参构造函数初始化为先前指定的值。
//
//	return 0;
//}

////构造函数示例三：具有二义性的构造函数。
//class A
//{
//public:
//	A()
//	{
//		_a = _b = _c = _d = 0;
//		_pi = nullptr;
//		_pj = nullptr;
//	}
//
//	A(int a = 0, int b = 0, int c = 0, int d = 0, int* pi = nullptr, int* pj = nullptr)
//	{
//		_a = a;
//		_b = b;
//		_c = c;
//		_d = d;
//		_pi = pi;
//		_pj = pj;
//	}
//
//	int _a, _b, _c, _d;
//	int* _pi, * _pj;
//};
//
//int main()
//{
//	//A a1;//错误，对类中"A"的构造函数的调用不明确，因其具有二义性。
//	A a2(1, 2, 3, 4, nullptr, nullptr);//调用全缺省的构造函数。
//	return 0;
//}

////构造函数示例四：编译器自动为类生成的隐式默认构造函数。
//class A
//{
//public:
//	A()//若此构造函数被注释，则编译器依旧会自动生成一个默认构造函数，只会对成员变量"_d"做处理，其余内置类型的成员变量都为随机值。
//	{
//		_a = _b = _c = 0;
//		_d = 0;//若此行被注释，在调用此默认构造函数时，成员变量"_d"的值依旧会被设置成给定的初始值(反汇编可见)。
//		_pi = nullptr;
//		_pj = nullptr;
//	}
//
//	int _a, _b, _c;
//	int _d = 99999999;//C++11中允许在类中给非静态数据成员指定初始值。
//	int* _pi, * _pj;
//};
//
//class Date//部分编译器会在此报警告：构造函数不初始化这些字段："_year"、"_month"、"_day"。
//{
//public:
//	void Print()
//	{
//		std::cout << "Print()：" << _year << "-" << _month << "-" << _day << std::endl;
//	}
//
//	A _a;//此类中包含了另一个类的成员变量，编译器会在此类中的默认构造函数调用另一个类的构造函数。
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;//此类中的默认构造函数只会对自定义类型的成员变量调用属于它的默认构造函数。
//
//	d1.Print();//构造函数不初始化这些字段："_year"、"_month"、"_day"，所以这里打印出来的是随机值。
//
//	std::cout << d1._a._a << '\n'
//			  << d1._a._b << '\n'
//			  << d1._a._c << '\n'
//			  << d1._a._d << '\n'
//			  << (d1._a._pi == nullptr) << '\n'
//			  << (d1._a._pj == nullptr) << std::endl;//可以发现，这些成员变量都被构造函数所初始化为对应的值。
//
//	return 0;
//}

/**
	析构函数：析构函数是对象生存期终结时调用的特殊成员函数，其目的是释放对象可能在它的生存期间获得的资源。
		1.析构函数的语法格式
			a.析构函数常见的语法格式为：~ 类名()，并且构造函数的名字与类名相同，且没有返回值和任何参数。
			b.与构造函数一样，析构函数也具有多种形式，此小节只演示常见的析构函数，其他形式的构造函数请参考文档。
		2.析构函数的特性
			a.一个类中只能有一个析构函数，且析构函数不能被重载，若类中没有显式的定义析构函数，则编译器会自动生成一个默认的析构函数。
			b.当一个对象的生命周期结束时，其析构函数会被自动调用。
			c.由编译器隐式生成的默认构造函数并不需要对其基本类型(内置类型)的成员变量进行资源清理，而是直接回收即可，但自定义类型的成员变量编译器会调用属于它类中的默认析构函数(若此成员变量的类中依旧没有显式定义默认析构函数，则编译器依旧生成默认析构函数，以此往复)。
		3.文档：https://zh.cppreference.com/w/cpp/language/destructor。
*/

////析构函数示例一：在类中显式定义析构函数。
//class A
//{
//public:
//	A()
//	{
//		_a = _b = _c = _d = 0;
//		_pi = nullptr;
//		_pj = nullptr;
//	}
//
//	~A()//析构函数
//	{
//		std::cout << "~A()：析构函数被调用" << std::endl;
//	}
//
//	int _a, _b, _c, _d;
//	int* _pi, * _pj;
//};
//
//int main()
//{
//	A a1;//调用类"A"中的默认构造函数。
//
//	return 0;//此时对象"a1"的生命周期结束，调用类"A"中的析构函数。
//}

////析构函数示例二：编译器自动为类生成的默认析构函数。
//class Time
//{
//public:
//	~Time()
//	{
//		std::cout << "~Time()：析构函数被调用" << std::endl;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;//此类中包含了另一个类的成员变量，编译器会在此类中的默认析构函数调用另一个类的析构函数。(构造函数不再赘述)
//};
//
//int main()
//{
//	Date d;
//	return 0;//此时对象"d"的生命周期结束，调用类"Date"中的析构函数。
//}

/**
	拷贝构造函数：构造函数的一种衍生，每当从同一类型的另一个对象初始化对象(通过直接初始化或复制初始化)时，都会调用拷贝构造函数。
		1.拷贝构造函数的语法格式：类名(类名& 标识符)。(可由"const"和"volatile"修饰括号内的类名)(此处为拷贝构造函数的典型声明)
			a.拷贝构造函数的语法格式类似与构造函数，但其首个形参需是以引用(左值)类型的形式出现，并且没有其他形参或是其他形参均有默认值。
			b.此小节只演示常见的拷贝构造函数的声明。
		2.拷贝构造函数的特性
			a.拷贝构造函数是构造函数的一个重载形式。
			b.拷贝构造函数的首个参数必须是以引用(左值)类型，是按照引用传递的方式传递的，若是以值传递的方式传递，则会重复调用拷贝构造函数，造成无限递归调用。
				a'.当进行直接初始化时，编译器会自动调用拷贝构造函数，但是如果拷贝构造函数是以值的形式传递的，当生成一份临时拷贝时就又会触发复制初始化，又调用拷贝构造函数，造成无限递归调用。
				b'.直接初始化详细文档参见：https://zh.cppreference.com/w/cpp/language/direct_initialization
				c'.复制初始化详细文档参见：https://zh.cppreference.com/w/cpp/language/copy_initialization。
			c.当类没有显式定义任何拷贝构造函数时，编译器会自动为其隐式生成一个默认拷贝构造函数，而如果当类中显式定义了默认拷贝构造函数时，编译器将不再为其隐式生成默认拷贝构造函数。
			d.由编译器隐式生成的默认拷贝构造函数只会对内置类型进行简单的内存拷贝，而对于自定义类型的成员变量，编译器会调用属于它类中的默认拷贝构造函数(若此成员变量的类中依旧没有显式定义默认拷贝构造函数，则编译器依旧生成默认拷贝构造函数，以此往复)。
			e.由编译器隐式生成的默认拷贝构造函数，只会进行简单的内存拷贝，也就是浅拷贝。
				a'.复制实参的每个标量子对象(递归地包含子对象的子对象，以此类推)，且不进行其他动作，不过不需要复制填充字节，甚至只要它们的值相同，每个复制的子对象的对象表示也不必相同，不允许在对象拷贝的过程中做任何额外的操作。
				b'.即通过简单地复制原始对象的所有变量的数据来创建一个对象，若是含有指针，则只会复制指针的值，而不会复制指针所指向的内存空间。
		3.文档：https://zh.cppreference.com/w/cpp/language/copy_constructor。
*/

////拷贝构造函数示例一：在类中显式定义拷贝构造函数。
//struct A
//{
//	//构造函数
//	A()
//	{
//		x_ = y_ = 10;
//	}
//
//	//拷贝构造函数的典型声明
//	A(const A& a)
//	{
//		x_ = a.x_;
//		y_ = a.y_;
//	}
//
//	int x_, y_;
//};
//
//int main()
//{
//	A a1;//调用类"A"中的默认构造函数。
//
//	std::cout << "a1.x_ = " << a1.x_ << '\n' << "a1.y_ = " << a1.y_ << std::endl;//对象"a1"中的成员变量"x_"和"y_"的值都为：10。
//
//	A a2(a1);//使用对象"a1"初始化对象"a2"，调用类"A"中的拷贝构造函数。
//
//	std::cout << "a2.x_ = " << a2.x_ << '\n' << "a2.y_ = " << a2.y_ << std::endl;//对象"a2"中的成员变量"x_"和"y_"的值都为：10。
//
//	A a3 = a1;//另一种初始化对象的方式，使用对象"a1"初始化对象"a3"，调用类"A"中的拷贝构造函数。
//
//	std::cout << "a3.x_ = " << a3.x_ << '\n' << "a3.y_ = " << a3.y_ << std::endl;//对象"a3"中的成员变量"x_"和"y_"的值都为：10。
//
//	return 0;
//}

////拷贝构造函数示例二：以值传递和以引用传递的拷贝构造函数。
//struct A
//{
//	//构造函数
//	A()
//	{
//		x_ = y_ = 10;
//	}
//
//	////错误的拷贝构造函数
//	//A(const A a)//当以值传递的方式传递参数时，生成临时拷贝时又会触发复制初始化，又调用拷贝构造函数，造成无限递归调用，部分编译器会直接报错处理：复制构造函数必须通过引用传递它的第一个参数。
//	//{
//	//	x_ = a.x_;
//	//	y_ = a.y_;
//	//}
//
//	//正确的拷贝构造函数
//	A(const A& a)
//	{
//		x_ = a.x_;
//		y_ = a.y_;
//	}
//
//	int x_, y_;
//};
//
//int main()
//{
//	A a1;//调用类"A"中的默认构造函数。
//
//	A a2(a1);//直接初识化的一种形式，使用对象"a1"初始化对象"a2"，调用类"A"中的拷贝构造函数。
//
//	A a3 = a1;//复制初识化的一种形式，使用对象"a1"初始化对象"a3"，调用类"A"中的拷贝构造函数。
//
//	return 0;
//}

////拷贝构造函数示例三：按值传递和按引用传递的函数，调用拷贝构造函数的时机。
//struct Test
//{
//	int x_;
//
//	Test()
//	{
//		std::cout << "构造函数" << '\n';
//		x_ = 0;
//	}
//
//	Test(const Test& t)
//	{
//		std::cout << "拷贝构造函数" << '\n';
//		x_ = t.x_;
//	}
//};
//
//void Func1(Test x)//按值传递，复制初始化，从另一个对象初始化对象会调用拷贝构造函数。
//{
//	std::cout << "Func1()\n";//完成拷贝构造后，才会打印此句。
//}
//
//void Func2(Test& x)//按引用传递，此处并不会产生临时变量，"x"就是调用此函数传递过来的参数的别名，也就不涉及拷贝构造函数的事情。
//{
//	std::cout << "Func2()\n";//直接打印此句。
//}
//
//int main()
//{
//	Test t1, t2;//调用两次构造函数。
//
//	//分别调用按值传递的函数和按引用传递的函数
//	Func1(t1);//调用"Func1"函数。
//	Func2(t2);//调用"Func2"函数。
//
//	return 0;
//}

////拷贝构造函数示例四：编译器自动为类生成的隐式默认拷贝构造函数。
//struct A
//{
//	//构造函数
//	A()
//	{
//		x_ = y_ = 10;
//	}
//
//	int x_, y_;
//};
//
//int main()
//{
//	A a1;//调用类"A"中的默认构造函数。
//
//	A a2(a1);//此时会调用编译器自动生成的隐式默认拷贝构造函数，将对象"a1"中成员变量的值逐字节拷贝给对象"a2"的成员变量。
//
//	std::cout << "a2.x_ = " << a2.x_ << '\n' << "a2.y_ = " << a2.y_ << std::endl;//对象"a2"中的成员变量"x_"和"y_"的值都为：10。
//
//	return 0;
//}

////拷贝构造函数示例五：编译器自动为类生成的隐式默认拷贝构造函数，并且类中有指针成员变量。
//struct A
//{
//	A()
//	{
//		x_ = y_ = 10;
//		px_ = &x_;
//		py_ = &y_;
//	}
//
//	int x_, y_;
//	int* px_, * py_;
//};
//
//int main()
//{
//	A a1;
//	A a2(a1);
//
//	std::cout << "a1.x_ = " << a1.x_ << '\n'
//			  << "a1.y_ = " << a2.y_ << '\n' << std::endl;//对象"a1"中的成员变量"x_"和"y_"的值都为：10。
//
//	std::cout << "a1.px_ = " << a1.px_ << '\n'
//			  << "a1.py_ = " << a1.py_ << '\n' << std::endl;//对象"a1"中的成员变量"px_"和"py_"的值都是其成员变量"x_"和"y_"的地址。
//
//	std::cout << "a2.x_ = " << a2.x_ << '\n'
//			  << "a2.y_ = " << a2.y_ << '\n' << std::endl;//对象"a2"中的成员变量"x_"和"y_"的值都为：10。
//
//	std::cout << "a2.px_ = " << a2.px_ << '\n'
//			  << "a2.py_ = " << a2.py_ << '\n' << std::endl;//发现对象"a2"中的成员变量"px_"和"py_"的值与对象"a1"中的成员变量"px_"和"py_"的值相同。
//
//	a2.x_ = 100;
//	a2.y_ = 100;
//
//	std::cout << "a1.x_ = " << a1.x_ << '\n'
//			  << "a1.y_ = " << a1.y_ << '\n'
//			  << "a2.x_ = " << a2.x_ << '\n'
//			  << "a2.y_ = " << a2.y_ << '\n' << std::endl;//修改对象"a2"中的成员变量"x_"和"y_"的值，对象"a1"中的成员变量"x_"和"y_"的值并不会改变。
//
//	*(a2.px_) = 20;
//	*(a2.py_) = 30;
//
//	std::cout << "a1.x_ = " << a1.x_ << '\n'
//			  << "a1.y_ = " << a1.y_ << '\n'
//			  << "a2.x_ = " << a2.x_ << '\n'
//			  << "a2.y_ = " << a2.y_ << '\n' << std::endl;//发现对象"a1"的成员变量"x_"和"y_"的值被修改了，而对象"a2"的成员变量"x_"和"y_"的值没有被修改。
//
//	return 0;
//}

////拷贝构造函数示例六：编译器自动为类生成的隐式默认拷贝构造函数，并且类中有指针成员变量，且指针成员变量指向的是堆内存，造成重复释放的错误。(错误示例)
//struct A
//{
//	A()
//	{
//		x_ = 10;
//		px_ = (int*)malloc(sizeof(int) * x_);
//	}
//
//	~A()
//	{
//		free(px_);//若"free"函数的参数"ptr"所指代的内存区域已经被释放，则行为未定义。
//	}
//
//	int x_;
//	int* px_;
//};
//
//int main()
//{
//	A a1;
//	A a2(a1);
//
//	std::cout << "a1.x_ = " << a1.x_ << '\n'
//			  << "a1.y_ = " << a1.px_ << '\n'
//			  << "a2.x_ = " << a2.x_ << '\n'
//			  << "a2.y_ = " << a2.px_ << '\n' << std::endl;
//
//	return 0;//此时对象"a1"和对象"a2"的生命周期结束，会调用各自的析构函数，而析构函数中的"free"函数会分别释放堆内存，但对象"a2"中的成员变量"px_"的值与对象"a1"中的成员变量"px_"的值相同，因此会造成重复释放的错误。
//}

////拷贝构造函数示例七：关于拷贝构造函数示例五的正确示例。
//struct A
//{
//	A()
//	{
//		x_ = 10;
//		px_ = (int*)malloc(sizeof(int) * x_);
//	}
//
//	A(const A& a)
//	{
//		x_ = a.x_;
//		px_ = (int*)malloc(sizeof(int) * x_);
//		memcpy(px_, a.px_, sizeof(int) * x_);
//	}
//
//	~A()
//	{
//		free(px_);
//	}
//
//	int x_;
//	int* px_;
//};
//
//int main()
//{
//	A a1;
//	A a2(a1);
//
//	std::cout << "a1.x_ = " << a1.x_ << '\n'
//			  << "a1.y_ = " << a1.px_ << '\n'
//			  << "a2.x_ = " << a2.x_ << '\n'
//			  << "a2.y_ = " << a2.px_ << '\n' << std::endl;
//
//	return 0;
//}