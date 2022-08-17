/*引用头文件*/
#include <stdio.h>
#include <string.h>

/*
	初识C语言
		01.第一个C语言程序
		02.C语言的基本数据类型
		03.常量和变量
		04.转义字符
		05.注释
		06.选择语句
		07.循环语句
		08.函数
		09.数组
		10.操作符
		11.关键字
		12.指针
		13.结构体
*/

/**
	第一个C语言程序
		1."main"函数是程序的入口：可以在文件中的任意位置；在一个工程中"main"函数有且仅有一个。
		2.使用"printf"函数可以在屏幕上打印出信息，在使用库函数时需要引用其对应的头文件。
*/

////第一个C语言程序示例
//int main()//"main"函数是程序的入口：可以在文件中的任意位置；在一个工程中"main"函数有且仅有一个。
//{
//	printf("打印的第一串代码\n");//"printf"：库函数，意为在屏幕上打印(输出)信息；"printf"的使用需要引用头文件"stdio.h"。
//	printf("打印的第二串代码\n");//"\n"：换行。
//	printf("打印的第三串代码\n");//C语言的每一条语句是以分号结尾的。
//	return 0;
//}

/**
	C语言的基本数据类型：为了更加丰富的表达生活中的各种值，就有了不同的数据类型。
		1.整型家族
			a."char"：最小的数据类型，其大小一定是一个字节，但，用于表示字符，但其依旧属于整型家族。
			b."short"：短整型，C语言规定"short"类型的大小不能大于"int"类型，也就是大小至少是两个字节。
			c."int"：整型，系统给定的基本整数类型，C语言规定"int"类型的大小至少为两个字节，通常依计算机的自然字长而定。
			d."long"：长整型，C语言标准规定"long"类型的大小只需大于或等于"int"类型的大小即可，但大小至少是四个字节。
			e."long long"：更长的整型，C语言标准规定"long long"类型的大小只需大于或等于"long"类型的大小即可，但大小至少是八个字节。
		2.浮点型家族
			a."float"：单精度浮点型，可至少精确表示小数点后六位的有效数字，一般情况下大小是四个字节。
			b."double"：双精度浮点型，可至少精确表示小数点后十位的有效数字，一般情况下大小是八个字节。
			c."long double"：多精度浮点型，于C90标准中添加，用于满足比"double"类型更高的精度要求，但C语言只保证其精度至少与"double"类型相同。
		3.计算数据类型的大小
			a.使用关键字"sizeof"可以计算出当前环境下所给的数据类型的大小。
			b."sizeof"是关键字，属于操作符，意为计算类型或者变量所占空间的大小，单位为字节。
			c.在不同环境下，数据类型的大小不尽相同，需通过"sizeof"计算可得知，但C语言标准规定了数据类型至少有多大。
*/

////计算数据类型的大小示例
//int main()
//{
//	//整型家族的大小
//	printf("%zu\n", sizeof(char));			//打印字符数据类型的大小；"%zu"：属于转换格式指定符(格式化数据)，意为以无符号整型的形式(格式)打印。
//	printf("%zu\n", sizeof(short));			//打印短整型的大小。
//	printf("%zu\n", sizeof(int));			//打印整型的大小。
//	printf("%zu\n", sizeof(long));			//打印长整型的大小。
//	printf("%zu\n", sizeof(long long));		//打印更长的整型的大小。
//
//	//浮点型家族的大小
//	printf("%zu\n", sizeof(float));			//打印单精度浮点数的大小。
//	printf("%zu\n", sizeof(double));		//打印双精度浮点数的大小。
//	printf("%zu\n", sizeof(long double));	//打印多精度浮点型的大小。
//
//	return 0;
//}

/**
	常量和变量
		1.常量：C语言中用于表示恒定不变的值为常量。
		2.变量：C语言中用于表示可以被改变的值为变量。
		3.局部变量和全局变量：变量的分类。
			a.局部变量：即在花括号内部定义的变量。
			b.全局变量：即在花括号外部定义的变量。
			c.当全局变量和局部变量名字相同的情况下，局部变量的数值优先。
			d.不建议把全局变量(甚至不建议使用全局变量)和局部变量的名字写成一样的。
		4.作用域和生命周期：作用域就是一个变量的所作用的范围，生命周期就是一个变量的创建和销毁之间的时间段。
			a.局部变量的作用域，就是变量所在的局部范围。
			b.全局变量的作用域，就是整个工程，当跨越文件时可能需要使用"extern"关键字进行声明。
			c.局部变量的生命周期：进入局部范围生命开始，出局部范围生命结束。
			d.全局变量的生命周期：整个程序的生命周期。
		5.四种形式的常量
			a.字面常量
			b.被"const"关键字修饰的常变量
				a'.本质依旧是变量，但是被"const"修饰，具有常属性(不能被改变的属性)。
				b'.被"const"修饰的常变量在C语言中只是在语法层面限制了变量不能直接被改变。
			c.使用"#define"预处理指令宏定义的标识符常量：主要在函数外部定义。
			d.使用"enum"关键字定义的枚举常量：指可以被一一列举的常量，如：性别、三原色等。
		6.字符串：即用双引号引起来的一串字符。
			a.字符串的结束标志是"\0"字符，它隐藏于字符串的结尾中，也可以显式的包含"\0"字符提前结束字符串。
			b.使用"strlen"函数计算字符串的长度
				a'.使用"strlen"函数需要引用头文件"string.h"。
				b'.在计算字符串长度的时候"\0"是字符串的结束标志，计入元素的个数但不计入字符串的长度。
			c.使用"char"字符数据类型可定义字符、字符串以及字符数组。
*/

////常量示例
//int main()
//{
//	13.14f;//"13.14"就是一个字面常量，而其后缀"f"用于表示它是一个"float"类型的数值(也可以大写)。
//
//	13.14;//此处是一个不带后缀的小数，也是一个字面常量，其默认是"double"类型的数值。
//
//	13.14l;//"l"为小数后缀表示"long double"类型的数值。
//
//	1314;//此处是一个不带后缀的小数，其默认是"int"类型的数值。
//
//	1314l;//"l"为整数后缀表示"long"类型的数值。
//
//	1314ll;//"ll"为整数后缀表示"long long"类型的数值。
//
//	'A';//字符常量，C语言中使用单引号引起来的单个字符，用于表示字符。
//
//	printf("%c\n", 'A');//"%c"：转换格式指定符，意为以字符的形式(格式)进行打印。
//
//	"Aoki";//C语言中并没有字符串类型，但具有字符串的概念，即用双引号引起来的一串字符，用于表示字符串，此处是一串字面常量字符串。
//
//	printf("%s\n", "Aoki");//此行意为将"Aoki"这一串常量字符串，以"%s"的形式(格式)进行打印，"%s"也是转换格式指定符，意为以字符串的形式(格式)进行打印。
//	
//	return 0;
//}

////变量示例
//int main()
//{
//	int attributes;//创建一个变量的格式：变量名前表示变量的数据类型，若无"="赋值符号，表示仅仅声明一个变量而不进行初始化。
//
//	int age = 18;//创建一个变量另一种格式：变量名前同样表示变量的数据类型，具有"="赋值符号表示声明一个变量的同时进行初始化，"="赋值符号后为需要给此变量的初始值。
//	
//	float height = 183.5f;//单精度变量赋值后面加"f"是表明该数字为单精度浮点型(float)。
//	
//	double weight = 60.5;//双精度变量不需要添加"f"，默认不添加即是双精度浮点型(double)。
//
//	age = age + 1;//改变一个变量。
//
//	printf("%d\n", age);//"%d"：转换格式指定符，意为以整型的形式(格式)进行打印；运行程序发现变量被改变了，同时证明了变量是可以被修改的。
//
//	height = height + 0.5f;
//	
//	weight = weight + 5;
//
//	printf("%f\n", height);//"%f"：代表单精度浮点型数据(float)。
//	
//	printf("%lf\n", weight);//"%lf"：代表双精度浮点型数据(double)。
//	
//	return 0;
//}

////局部变量与全局变量示例
//int a = 100;//全局变量，在花括号外部定义。
//
//int b;//未初始化的全局变量，全局变量未初始化时，编译器会默认将其值初始化为"0"。
//
//int main()
//{
//	int a = 10;//局部变量，在花括号内部定义。
//
//	int c;//未初始化的局部变量，局部变量未初始化时，变量的值是不确定的，取决于编译器。
//	
//	printf("%d\n", a);//运行程序后发现值为：10。
//
//	printf("%d\n", b);//运行程序后发现值为：0。
//	
//	printf("%d\n", c);//值是不确定的，取决于编译器。
//	
//	return 0;
//}

////常量和变量例题：求两个整数的和。
//int main()
//{
//	int sum, num1, num2;//这是一个连续声明变量的例子，此处各个变量的类型都为"int"类型。
//	
//	scanf_s("%d%d", &num1, &num2);//"scanf_s"：输入函数，类似于"scanf"函数，但在"VS2022"中不做屏蔽警告处理无法使用"scanf"函数，因其不安全。
//	
//	sum = num1 + num2;
//	
//	printf("%d + %d = %d\n", num1, num2, sum);
//	
//	return 0;
//}

////作用域和生命周期示例
//int year = 2022;//此处的"year"就是一个全局变量。
//
//int main()
//{
//	int a = 10;
//
//	printf("a = %d\n", a);//局部变量"a"于此起作用，此处的花括号内就是它的作用域，当一个变量离开它的作用域时，变量就会被销毁。
//
//	return 0;
//}

////四种形式的常量示例
//int main()
//{
//	////字面常量
//	//3.14, 10, 'a', "abcdef";
//	
//	////被"const"修饰的常变量
//	//const int num = 10;
//	////num = 20;//取消注释后编译器报错：表达式必须是可修改的左值。
//	//printf("num=%d\n", num);
//	
//	////"#define"定义的标识符常量
//	//#define MAX 10000
//	//int max = MAX;
//	//printf("%d\n", MAX);
//	
//	////枚举常量
//	//enum Sex//括号内就是这种枚举常量的未来取值，有且只能取其中的一个。
//	//{
//	//	//花括号中的"man"、"woman"、"secrecy"都属于枚举常量。
//	//	man = 1,//赋上一个最初始的值，若不赋值则为"0"。
//	//	woman,//从"man"开始依次往下递增，故此处"woman"为"2"。
//	//	secrecy//此处"secrecy"为"3"。
//	//};
//	//printf("man = %d\n", man);			//打印的值为：1。
//	//printf("woman = %d\n", woman);		//打印的值为：2。
//	//printf("secrecy = %d\n", secrecy);	//打印的值为：3。
//
//	return 0;
//}

////字符串示例
//int main()
//{
//	//字符串字面常量示例
//	"abcdef";
//	
//	//创建字符数组(使用双引号引起的字符串)示例
//	char arr1[] = "abcd";//方括号中没有定义元素个数，默认根据后面的双引号中的元素定义。
//	printf("%zu\n", sizeof(arr1));//使用"sizeof"计算元素个数，可知数组"arr"共有"5"个元素，在结尾位置隐藏了一个"\0"的字符。
//	
//	//创建字符数组(使用单引号引起的单个字符)示例
//	char arr2[] = { 'a','b','c' };
//	char arr3[] = { 'a','b','c','\0'};
//	printf("%s\n", arr1);//打印出"4"个字符。
//	printf("%s\n", arr2);//打印出乱码：因为使用单引号字符的字符数组不会默认添加"\0"作为结束标志。
//	printf("%s\n", arr3);//手动放下"\0"，打印出3个字符，并且没有乱码。
//
//	//使用"strlen"求字符串长度示例
//	printf("%zu\n", strlen("abc"));//打印出的结果为：3；也代表了"\0"不算入字符串长度。
//	printf("%zu\n", strlen(arr1));//打印出的结果为：4。
//	printf("%zu\n", strlen(arr2));//打印出的结果为：随机值；因为其没有字符串的结束标志，故"strlen"函数并不知道何时结束。
//
//	return 0;
//}

/**
	转义字符
		1.转义字符为转变了字符原有意思的字符，即不是字符本来的意思了。
		2.常用转义字符
			a." \? "：在书写连续多个问号时使用，防止他们被解析成三字母词。
			b." \' "：用于表示字符常量单引号" ' "。
			c." \" "：用于表示一个字符串内部的双引号。
			d." \\ "：用于表示一个反斜杠，防止它被解释为一个转义序列符。
			e." \a "：警告字符，蜂鸣，可使本机发出声音。
			f." \b "：退格符。
			g." \f "：换页符。
			h." \n "：换行符。
			i." \r "：回车符。
			j." \t "：水平制表符。
			l." \v "：垂直制表符。
			m." \ddd "："ddd"表示一至三个八进制的数字。
			n." \xdd "："dd"表示两个十六进制的数字。
*/

////转义字符使用示例
//int main()
//{
//	printf("\n");					//打印发现空了一行，因为转义字符"\n"意为换行。
//	printf("c:\test\test.c\n");		//无法打印出"\t"，因为"\t"为转义字符(横向制表(Tab))。
//	printf("c:\\test\\test.c\n");	//可在"\t"前再加入"\"防止被转变。
//	printf("(are you ok??)");		//在一些编译器中"??)"属于三字母词会被转义成"]"。
//	printf("%c\n", '\'');			//不加"\"会出现语法问题，因为落单了一个单引号。
//	printf("\a");					//"\a"：属于转义字符，意为蜂鸣。
//
//	//转义字符"\ddd"(八进制)和"\xdd"(十六进制)的运用
//	printf("%c\n", '\130');//八进制的"130"为十进制的"88"，选用ASCII码值表中的88对应的字符"X"表示，故打印结果是：X。
//	printf("%c\n", '\101');//八进制的"101"为十进制的"65"，在ASCII码值表中"65"代表字符"A"。
//	printf("%c\n", '\x30');//十六进制的"30"为十进制"48"，在ASCII码值表中"48"代表字符"0"。
//	printf("%d\n", '\130');//因为"printf"打印的格式是"%d"整型，故结果是：88。
//	printf("%zu\n", strlen("c:\test\108\test.c"));//计算出字符串的长度是为：14；注意"8"不属于八进制。
//	
//	return 0;
//}

//注释：注释是用于解释代码的。
//	1.C语言的注释风格为：" /*...*/ "，不支持嵌套注释，即遇到第一个"*/"就代表注释结束了。(知道我这里为什么用" // "了吧...)
//	2.C++语言的注释风格为：" // "，C语言将其引入。

/**
	选择语句：又称为分支语句。
		1.具有"if"关键字、"else"关键字和"else if"关键字。
		2.选择语句关键字后的括号内的表达式的结果为真则进入代码块，为假不进入。
		3.在C语言中，零表示为假，非零表示为真。
*/

////选择语句示例
//int main()
//{
//	int input = 0;
//	printf("你是Gay吗？\n请输入是或不是(是代表1，不是代表2)>");
//	scanf_s("%d", &input);
//	if (input == 1)
//	{
//		printf("\n那你是1还是0嘞？(不要跟我说你是0.5哦~)\n请输入1或0>");
//		scanf_s("%d", &input);
//		if (input == 1)
//		{
//			printf("\n这不发个微信来嘛哈哈哈(bushi)。\n");
//		}
//		if (input == 0)
//		{
//			printf("\n呜呜呜好兄弟，两个0是没有好结果的。\n");
//		}
//		else
//		{
//			printf("\n输入的什么玩意给我重新打开再来一次。\n");
//		}
//	}
//	else if (input == 2)
//	{
//		printf("\n拒绝恐同，从我做起！\n");
//		return 0;
//	}
//	else
//	{
//		printf("\n输入的什么玩意给我重新打开再来一次。\n");
//	}
//	return 0;
//}

/**
	循环语句：可以循环执行的语句(代码段)。
		1.具有"while"循环、"for"循环、"do-while"循环。
*/

////循环语句示例："while"循环。
//int main()
//{
//	int line = 0;
//	while(line < 30000)
//	{
//		printf("写代码：%d行。\n", line);
//		line = line + 1;
//	}
//	if (line == 30000)
//	{
//		printf("\n恭喜达成成就：写代码30000行。\n");
//	}
//	return 0;
//}

/**
	函数：简化代码，代码复用。
*/

////函数示例
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;//返回的值为"z"。
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d%d", &num1, &num2);
//	printf("%d", Add(num1, num2));
//	return 0;
//}

/**
	数组：一组相同类型的元素的集合。
		1.下标：即数组元素的索引值，从"0"开始为第一个元素，以此递增，可使用方括号以及方括号内加上下标以获取或访问数组元素。
*/

////数组示例
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//完全初始化。
//	char ch[5] = "abc";//不完全初始化，剩余元素补充为："\0"。
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d ", arr[i]);//第一次打印为下标为"0"的元素"1"。
//		i = i + 1;
//	}
//	return 0;
//}

/**
	操作符：指令系统的每一条指令都有一个操作符，它表示该指令应进行什么性质的操作，也就是说操作符是能够完成一些操作的符号。
 */

////操作符示例一
//int main()
//{
//	int a = 9 / 2;
//	printf("%d\n", a);//打印的结果为：4。
//	
//	float b = 9.0 / 2;//两端需要取一个为小数，答案才能为"4.500000"，因若为整数，两整数运算结果还是整数。
//	printf("%f\n", b);//打印的结果为：4.500000。
//	
//	int c = 9 % 2;//"%"：取模(余数)操作符。
//	printf("%d\n", c);//打印的结果为：4.500000。
//	
//	int d = 2;
//	int e = d << 1;//左移操作符：移动的是二进制位，右边补"0"；此处意为将变量"d"的二进制序列向左移动"1"位后的结果赋值的"e"变量。
//	printf("%d\n", e);//打印的结果为：4。
//	
//	int f = 0;//C语言中"0"表示假，非"0"表示真，并不是"1"就表示真。
//	printf("%d\n", !f);//逻辑反操作符：一般非"0"表示为"1"，多应用于分支语句中的表达式。
//	
//	int arr[10] = { 0 };//如何计算数组的总大小：此处的数组存放的元素是整型元素，而当前环境下的整型元素是四个字节，数组有"10"个元素，故数组大小为"10 * 4"个字节。
//	printf("%d\n", (int)sizeof arr);//"(int)"：强制类型转换为"int"，将原有类型强制转换为圆括号内的类型，此处是将"sizeof"计算的结果的数值类型转换为"int"类型。
//	
//	int size = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数：使用数组的总大小除去数组单个元素的大小。
//	printf("%d\n", size);
//	
//	return 0;
//}

////操作符示例二："~"按二进制位取反(把所有一个数的二进制位，"1"变成"0"，"0"变成"1")。
//int main()
//{
//	int a = 0;
//	//一个整数的二进制表示形式有三种：原码、反码、补码，并且整数在内存存储的是补码。
//	//正数：原码、反码、补码相同。
//	//负数：二进制的最高位表示为符号位，而负数最高位为"1"，负数的原码变反码是符号位不变，其余按位取反为反码，而反码加"1"为补码。
//	
//	printf("%d\n", ~a);//打印的是原码，内存存储的是补码。
//	
//	return 0;
//}

////操作符示例三："++"和"--"。(只列举++的例子，--同理)
//int main()
//{
//	int a = 10, b = 0;
//
//	b = ++a;//前置"++"：先加后使用；
//	printf("%d\n", a);//打印结果为：11。
//	printf("%d\n", b);//打印结果为：11。
//
//	b = a++;//后置"++"：先使用后加；
//	printf("%d\n", a);//打印结果为：12。
//	printf("%d\n", b);//打印结果为：11。
//
//	return 0;
//}

////操作符示例四："(类型)"强制类型转换。
//int main()
//{
//	//int a = 3.14;//程序运行(编译)会报警告：从"double"转换到"int"，可能丢失数据。
//	int a = (int)3.14;//强制转换"double"类型为"int"类型，再次运行程序(编译)便无警告。
//	printf("%d\n", a);
//	return 0;
//}

////操作符示例五："&&"逻辑与和"||"逻辑或。
//int main()
//{
//	//int a = 1; int b = 1; int c = a && b;
//	//printf("%d\n", c);//结果为：1，意思为当"a"和"b"中都为真则为真。
//
//	//int a = 1; int b = 0; int c = a && b;
//	//printf("%d\n", c);//结果为：0，意思为当"a"和"b"中只要有一个为假则都为假。
//
//	//int a = 1; int b = 0; int c = a || b;
//	//printf("%d\n", c);//结果为：1，意思为当"a"和"b"中只要有一个为真则为真。
//	return 0;
//}

////操作符示例六："else1 ? else2 : else3"，又名三目操作符，其中"else"为表达式，此操作符意为当"else1"成立则采用"else2"的结果，否则采用"else3"的结果。
//int main()
//{
//	int a = 0;
//	int b = 3;
//	int max = 0;
//
//	max = a > b ? a : b;//如果"a > b"成立这结果为"a"否则为"b"，然后再将值赋给"max"变量。
//	
//	printf("%d\n", max);
//
//	return 0;
//}

////操作符示例七：逗号表达式是用逗号隔开的一串表达式，它是从左向右依次计算的，并且整个表达式的结果是最后一个表达式的结果。
//int main()
//{
//	int a = 0;int b = 3;int c = 5;
//	
//	int d = (a = b + 2, c = a - 4, b = c + 2);//依次计算，变量"b"的值赋给了变量"d"。
//	
//	printf("%d\n", d);//结果为：3。
//	
//	return 0;
//}

////操作符示例八：下标引用操作符。
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", arr[5]);//获取数组下标为"5"的元素的值。
//	return 0;
//}

////操作符示例九：函数调用操作符，当调用函数的时候，函数名后边的括号就是函数调用操作符。
//int main()
//{
//	printf("Hello World!\n");//"printf"函数后的圆括号就是函数调用操作符。
//	return 0;
//}

/**
	关键字：由C语言提供。
		1.不能自己创建关键字，并且变量名不可与关键字同名(区分大小写)。
 */

////关键字示例
//int main()
//{
//	//"extern"：声明外部符号。
//
//	//"void"表示无或者空的意思。
//
//	//"auto"：每个局部变量都有"auto"修饰，但被自动省略掉了；同时"auto"在新的C语言语法中也有其他用法，暂时不考虑。
//	{
//		auto int a = 0;//自动创建，自动销毁的，即为自动变量。
//		int b = 0;//auto省略掉了。
//	}
//	
//	//register关键字：大量或频繁被使用的数据，放在寄存器中可提升效率；
//	{
//		register int a = 0;//建议变量"num"的值存放在寄存器中(编译器说的算，只是建议)，寄存器存在于存储类元件的速度金字塔顶尖。
//	}
//						 
//	//"define"和"include"不是关键字，是预处理指令。
//	//"define"可定义标识符常量、可定义宏。
//	{
//		#define MAX 1000//定义标识符常量。
//		printf("%d\n", MAX); 
//	}
//	{
//		#define ADD(X,Y) ((X)+(Y))//定义宏，注意此处的括号。
//		printf("%d\n", 4 * ADD(2, 3));//先乘除后加减，若上行不加括号则打印结果为：11。
//	}
//
//	//"typedef"：类型重定义，即类型重命名。
//	{
//		typedef unsigned int u_int;//将"unsigned"起了个别名叫"u_int"，意义在于缩短了名字。
//		unsigned int a = 100;//"unsigned"：意为无符号的。
//		u_int b = 100;//可以发现同时起作用。
//	}
//	 
//	//存储的区域分为栈区(局部变量和函数参数)、堆区(动态内存分配的)和静态区(全局变量、静态变量、"static"修饰的变量)等。
//	//"static"：静态的，用来修饰变量和函数的；"static"修饰局部变量、全局变量、函数。
//	//"static"修饰的局部变量，总是存在内存的静态区，即使变量所存在的函数运行介绍，这个静态变量的值也不会被销毁，能够重复使用这个值。
//	//"static"修饰的全局变量，使得这个全局变量只能在自己所在的源文件(.c)内部可以使用(外部文件使用"extern"声明也无法使用)；本质是把全局变量的外部链接属性更改为内部链接属性。
//	//"static"修饰的函数同全局变量(上一行)。
//	//"static"修饰的局部变量是在程序的编译阶段就分配好了地址，可调试转反汇编查看以下代码，可发现"static"没有对应的汇编指令，并且调试不执行"static"的代码。
//	{
//		int i = 0;
//		while (i < 10)
//		{
//			static int a = 1;//"static"修饰的局部变量出局部变量作用域后被保留了，改变了局部变量的生命周期(本质上是改变了变量的存储区域)。
//			a++;
//			printf("%d ", a);//打印的结果为：2 3 4 5 6 7 8 9 10 11。
//			i++;
//		}
//	}
//	
//	return 0;
//}

/**
	指针
		1.指针是内存中一个最小单元的编号，也就是地址，地址是用来唯一标示一块内存空间的，一个内存单元的大小是一个字节，一个字节对应了一个地址。
		2.指针通常指的是指针变量，是用来存放内存地址的变量，可通过取地址操作符取出变量的内存起始地址，将其存放到指针变量中。
		3.在"32"位机器中，地址是由"32"个"0"或"1"组成二进制序列，那么地址就得用"4"个字节的空间来存储，故一个指针变量的大小就是"4"个字节。
		4.在"64"位机器中，地址是由"64"个"0"或"1"组成二进制序列，那么地址就得用"8"个字节的空间来存储，故一个指针变量的大小就是"8"个字节。
*/

////指针示例一
//int main()
//{
//	int a = 10;//当前环境下变量"a"在内存中分配的空间为四个字节。
//	printf("%p\n", &a);//"%p"：转换格式指定符(格式化数据)，意为以指针(地址)的形式(格式)打印。
//	
//	int* pa = &a;//变量"pa"是用来存放地址的，在C语言中"pa"叫指针变量，"*"说明"pa"是指针变量，"int"说明"pa"指向的对象是"int"类型的，而此处的"&"操作符意为取出变量"a"的地址(取出的是变量"a"第一个字节的地址)。
//	*pa = 20; //"*"：间接访问操作符，又称解引用操作符，此处的"*pa"就是通过"pa"里边的地址，找到变量"a"，并赋值为"20"。
//	
//	return 0;
//}

////指针示例二：计算指向不同数据类型的指针变量的大小。
//int main()
//{
//	//可发现以下结果都相同，当前环境下为"X64"环境，故结果为：8。
//	printf("%zu\n", sizeof(char*));
//	printf("%zu\n", sizeof(short*));
//	printf("%zu\n", sizeof(int*));
//	printf("%zu\n", sizeof(long*));
//	printf("%zu\n", sizeof(long long*));
//	printf("%zu\n", sizeof(float*));
//	printf("%zu\n", sizeof(double*));
//	return 0;
//}

/**
	结构体：结构体使得C语言有能力描述出复杂对象的类型，而且可以让C语言创建新的数据类型。
 */

////结构体示例
//struct Stu//"struct"：创建结构体类型的关键字。
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//struct Book
//{
//	char name[20];
//	float price;
//	char id;
//};
//
//int main()
//{
//	struct Stu s = { "Aoki",19,99.9 };//结构体的创建和初始化。
//	
//	printf("1：%s %d %lf\n", s.name, s.age, s.score);//"."操作符：以结构体访问结构体成员，即左操作数为结构体，右操作数为结构体成员名。
//	
//	struct Stu *ps = &s;//将以"struct Stu"结构体类型创建的变量"s"的地址交给指针变量维护。
//	
//	printf("2：%s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
//
//	printf("3：%s %d %lf\n", ps->name, ps->age, ps->score);//"->"操作符：以结构体指针访问结构体成员，即左操作数为结构体的指针，右操作数为结构体成员名。
//
//	return 0;
//}