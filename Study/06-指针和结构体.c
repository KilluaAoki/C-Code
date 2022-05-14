#include <stdio.h>

/*
	表达式求值
		1.表达式求值的顺序一部分是由操作符的优先级和结合性决定。
		2.有些表达式的操作数在求值的过程中可能需要转换为其他类型。
		3.表达式如果不能通过操作符的属性确定唯一的计算路径，那这个表达式就是存在问题的。
*/

/*
	隐式类型转换
		1.整型提升
			a.C的整型算术运算总是至少以缺省整型类型的精度来进行的。
			b.为了获得精度，表达式中的字符(char)和短整型操作数(short)在使用之前被转换为普通整型，这种转换称为整型提升。
			c.CPU内整型运算器(ALU)的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度。
			d.整型提升是按照变量的数据类型的符号位来提升的；对于无符号的整形提升，则高位补0。
		2.算术转换
			a.若操作符的各个操作数属于不同的类型，那么除非其中一个操作数的转换为另一个操作数的类型，否则操作就无法进行。
			b.如果某个操作数的类型在层次体系中排名较低，那么首先要转换为另外一个操作数的类型后执行运算。
			c.层次体系：long double>double>float>unsigned long int>long int>unsigned int>int。
*/

////整型提升例一
//int main()
//{
//	char a = 3;
//	//“int“类型中完整的“a”的二进制序列：00000000000000000000000000000011。
//	//“char”类型中发生截断后“a”的二进制序列：00000011。
//	
//	char b = 127;
//	//“int“类型中完整的“b”的二进制序列：00000000000000000000000001111111。
//	//“char”类型中发生截断后“b”的二进制序列：01111111。
//	
//	char c = a + b;//“a”与“b”都为字符型，没有达到整型大小，计算会发生整型提升。
//	//“a”：00000000000000000000000000000011。
//	//“b”：00000000000000000000000001111111。
//	//“c”：00000000000000000000000010000010。
//	//发现“c”为”char“类型，故截断”c”为：10000010。
//	
//	printf("%d\n", c);//打印的结果为：-126。
//	//发现“%d”需要打印出整型，故“c”进行整型提升为：11111111111111111111111110000010。
//	//倒推反码：11111111111111111111111110000001；
//	//倒退原码：10000000000000000000000001111110；
//	//得出答案结果为：-126。
//
//	return 0;
//}

////整型提升例二
//int main()
//{
//	char a = 0xb6;//10110110
//	
//	short b = 0xb600;//1011011000000000
//	
//	int c = 0xb6000000;
//
//	if (a == 0xb6)
//		printf("a");//无法打印：经过了整型提升，变成负数，故不相同。
//	
//	if (b == 0xb600)
//		printf("b");//无法打印：经过了整型提升，变成负数，故不相同。
//	
//	if (c == 0xb6000000)
//		printf("c");//打印成功：没有经过整型提升。
//
//	return 0;
//}

////整型提升例三
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c)); //1
//	printf("%u\n", sizeof(+c));//参与运算发生了整型提升(变量“c”本身不会发生变化)，故打印结果为：4。
//	printf("%u\n", sizeof(-c));//同上
//	printf("%u\n", sizeof(!c));//于VS2022中，结果为：1；使用gcc编译并运行，结果为：4。
//	return 0;
//}

////关于sizeof关键字
////	1.详见操作符笔记(2022_02_05)。
////	2.关于变量是有两个属性的，分别为：值属性与类型属性；sizeof会推导运算出类型属性。
//int main()
//{
//	short s = 5;
//	sizeof(s = a + 3);//推导运算出类型属性，故才能打印出：2。
//	return 0;
//}

////算术转换：算术转换需要合理，否则会有一些潜在的问题，如：丢失精度等。
//int main()
//{
//	int a = 4;
//	float b = 4.5f;
//	a + b;//类型不相同，会发生算术转换；由精度较低的“int”类型转换为精度较高的“float”类型。
//	
//	float c = 3.14;
//	int num = c;//发生算术转换，但会丢失精度。
//	
//	return 0;
//}

/*
	操作符的属性
		1.影响复杂表达式求值的三个影响因素：操作符的优先级；操作符的结合性；是否控制求值顺序。
		2.表达式中相邻的操作符先执行哪个是取决于优先级的；如果优先级相同，则取决于结合性。
*/

////影响复杂表达式求值的三个影响因素：具体请查阅”操作符优先级“表格。
//int main()
//{
//	int a = 4;
//	int b = 5;
//	
//	int c = a + b * 7;//决定计算顺序因素：优先级。
//	int d = a + b + 7;//决定计算顺序因素：结合性。
//
//	//是否控制求值顺序
//	//	1.唯有4个操作符符合：“&&”、“||”、“?:”、“,”。
//	//	2.除逗号表达式外，若操作符运算符合条件，则不符合的不进行运算。
//	//	3.逗号表达式中，从左向右依次计算，但是整个表达式的结果是最后一个表达式的结果。
//	
//	return 0;
//}

////问题表达式例一
//int main()
//{
//	int a = 0, b = 0;
//	
//	a * a + a * a + a * a;//由于“*”比“+”的优先级高，只能保证“*”的计算比“+‘早，但优先级并不能决定第三个”*“比第一个”+“早。
//		
//	b + --b;//操作符的优先级只能决定“--”的运算在“+”的运算的前面，但“+”的左操作数的获取在右操作数求值之前还是之后是不得而知的。
//	
//	return 0;
//}

////问题表达式例二：来自《C和指针》；在不同编译器会产生不同的结果。
//int main()
//{
//	int i = 10;
//	i = i-- - --i * (i = -3) * i++ + ++i;
//	printf("i = %d\n", i);
//	return 0;
//}

////问题表达式例三
//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun() * fun();//函数的调用先后顺序无法通过操作符的优先级确定。
//	printf("%d\n", answer);
//	return 0;
//}

////问题表达式例四：可调试查看汇编代码，得知顺序。
//int main()
//{
//	int i = 1;
//	int ret = (++i) + (++i) + (++i);
//	printf("%d\n", ret);
//	printf("%d\n", i);
//	return 0;
//}

/*
	指针
		1.指针是内存中一个最小单元的编号，也就是地址，地址是唯一标示一块地址空间的。
		2.指针通常指的是指针变量，是用来存放内存地址的变量，可通过取地址操作符取出变量的内存地址，将其存放到指针变量中。
		3.32位机器，地址是由32个0或1组成二进制序列，那么地址就得用4个字节的空间来存储，所以一个指针变量的大小就是4个字节。
		4.64位机器，原理同第三条，故一个指针变量的大小就是8个字节，所以指针的大小在32位平台是4个字节，在64位平台是8个字节。
*/

////指针使用示例
//int main()
//{
//	int a = 10;//在内存中开辟出一块空间，变量“a”占用了4个字节的空间，即占用了4块内存空间，每一个小的内存单元为1个字节。
//	int* pa = &a;//这里将“a”的4个字节的第一个字节地址使用取地址操作符将地址存放在了指针变量“pa”中；一个字节对应了一个地址。
//	*pa = 20;//对指针变量“pa”进行解引用，对“a”进行间接访问，从而更改“a”的值。
//	return 0;
//}

/*
	指针和指针类型
		1.指针类型决定了指针的解引用权限(能访问几个字节)。
		2.指针类型决定了指针每走一步能走多远，即步长或距离(能移动几个字节)。
*/

////指针和指针类型示例
//int main()
//{
//	int a = 0x11223344;//1个十六进制位需要4个二进制位表示。
//	int arr[10] = { 0 };
//	
//	//解引用权限示例
//	char* pa = &a;
//	*pa = 0;//调试发现只有一个字节变成了”00“。
//	int* pb = &a;
//	*pb = 0;//调试发现四个字节变成了”00“，说明了指针类型决定了指针的解引用权限。
//	
//	//步长示例
//	int* pc = arr;
//	char* pd = arr;//发现“char*”类型的指针变量同样可以存放下数组首元素的地址。
//	printf("%p\n", pc);
//	printf("%p\n", pd);//打印发现和“pc”存放的地址相同。
//	printf("%p\n", pc + 1);
//	printf("%p\n", pd + 1);//打印发现和“pc + 1”表达式所得出的结果不同，因为“char*”类型决定了这个指针的步长为一个字节。
//	
//	return 0;
//}

////指针和指针类型的应用
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0 };
//	char* pa = &arr1;
//	int* pb = &arr2;
//	for (int i = 0; i < 10; i++)
//	{
//		*(pa + i) = 1;//调试发现每次循环跳过一个字节，并且前十个字节的内容更改了。
//		*(pb + i) = 1;//调试发现每次循环跳过四个字节，并且每个数组元素都改为了“1”。
//	}
//	return 0;
//}

/*
	野指针：野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）。
		1.野指针成因：非法访问、越界访问、指针指向的空间释放。
		2.规避野指针：指针初始化、小心指针越界、指针指向空间释放及时置成空(NULL)值、避免返回局部变量的地址、使用指针前检查其有效性。
		3.规避野指针的好处是要么指针指向的是空值是空指针，要么指针指向的就是有效的地址，这样再检查其有效性就能尽量规避野指针减少错误。
*/

////野指针示例
//int* test()
//{
//	int a = 0;
//	return &a;
//}
//int main()
//{
//	//非法访问错误示例
//	//int* p;//未初始化的局部指针变量，默认存放的是随机值。
//	//*p = 1;//ERR：使用了未初始化的局部变量“p”。
//
//	//越界访问错误示例
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//for (int i = 0; i <= 10; i++)
//	//{
//	//	*(p + i) = 1;//ERR：变量“arr”周围的堆栈已损坏，程序崩溃；因为当循环到第10次时，指针所指向的位置非数组范围，造成越界访问。
//	//}
//
//	//指针指向的内存空间释放示例：具体详见动态内存。
//	int* p = test();
//	*p = 20;//ERR：局部变量或临时变量离开所在函数体后会被释放，故对返回的局部变量或临时变量的地址进行解引用会造成非法访问。
//
//	return 0;
//}

////规避野指针示例
//int main()
//{
//	//指针初始化：当不知道指针变量应初始化为什么的时候，应直接初始化为空(NULL)值。
//	int* pa = NULL;//对“NULL”右键转到定义会发现其实是将“0”强制类型转换为“void”指针类型。
//	*pa = 10;//调试发现会引发异常：写入访问权限冲突，pa是nullptr；所以要检查其有效性规避此问题。
//
//	//小心指针越界：C语言本身是不会检查数据的越界行为的，需自行注意。
//	
//	//指针指向空间释放及时置成空(NULL)值
//	
//	//使用指针前检查有效性
//	int* pb = NULL;
//	if (*pb != NULL)//检查有效性。
//	{
//		*pb = 10;
//	}
//	
//	return 0;
//}

/*
	指针运算
		1.指针“+”、“-”整数。
		2.指针“-”指针。
		3.指针的关系运算。
*/

////指针“+”、“-”整数&指针的关系运算示例，请调试观察数组元素的变化。
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	for (int* pa = arr; pa < &arr[5]; pa++)//“pa < &arr[5]”就进行了指针的关系运算；“pa++”就进行了指针“+”整数运算。
//	{
//		*pa = 0;
//	}
//	return 0;
//}

////指针“-”指针示例：注意使用指针“-”指针应满足两指针指向同一块内存空间。
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* pa = &arr[0];
//	int* pb = &arr[9];
//	printf("%lld\0", pb - pa);//打印的结果为：9，也就是说此代码指针“-”指针得到结果是两个指针之间的元素个数。
//	return 0;
//}

////指针的关系运算示例：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	
//	for (int* pa = &arr[5]; pa > &arr[0];)//“&arr[5]”实际上没有进行访问，所以并不构成越界访问。
//	{
//		*--pa = 0;
//	}
//	
//	for (int* pa = &arr[5-1]; pa >= &arr[0]; pa--)//C语言标准并不保证此段代码可行。
//	{
//		*pa = 0;
//	}
//	
//	return 0;
//}

////指针运算例一：模拟”strlen“函数。
//int my_strlen(char* pa)
//{
//	char* flag = pa;
//	while (*pa != '\0')
//	{
//		pa++;
//	}
//	return pa - flag;
//}
//int main()
//{
//	printf("%d\n", my_strlen("Aoki"));
//	return 0;
//}

////指针和数组示例
//int main()
//{
//	int arr[10] = { 0 };
//
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);//可见打印结果相同说明：数组名是数组首元素的地址。
//
//	int* pa = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%p <===> %p\n", &arr[i], pa + i); //可见打印结果相同说明：“pa+i”就是数组下标为“i”的元素地址。
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		*(pa + i) = i;//利用指针将数组元素初始化成“i”对应的数字。
//		printf("%d ", *(pa + i));//利用指针将数组元素打印出来。
//	}
//
//	return 0;
//}

////一段能让小朋友懵逼的代码
////	推算原理：arr[2] <==> *(pa+2) <==> *(2+pa) <==> *(arr+2) <==> *(2+arr) <==> 2[arr] <==> 2[pa] <==> pa[2]。
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* pa = arr;
//	
//	printf("arr[2]=%d <==> pa[2]=%d\n", arr[2], pa[2]);//下标引用操作符：[]；”2“和“arr”是两个操作数。
//	printf("2[arr]=%d <==> 2[pa]=%d\n", 2[arr],2[pa]);
//
//	return 0;
//}

/*
	二级指针
*/

////二级指针示例
//int main()
//{
//	int a = 0;
//	int* pa = &a;//“pa”是指针变量，属于一级指针。
//	int** ppa = &pa;//因为“pa”为指针变量，同样是在内存中开辟一块内存空间，故可以把“pa”的地址用取地址操作符取出存放在另一个指针变量“ppa”中，此处“ppa”就属于二级指针。
//	**ppa = 10;//通过“*ppa”找到“pa”，再通过解引用操作符从而找到“a”。
//	return 0;
//}

/*
	指针数组：存放指针的数组。
*/

////指针数组示例
//int main()
//{
//	int arr1[5] = { 0 };//整型数组：存放整型的数组。
//	char arr2[5] = "Aoki";//字符数组：存放的是字符。
//	int* parr1[5] = { &arr1[0],&arr1[1],&arr1[2],&arr1[3],&arr1[4] };//整型指针数组：存放整型指针的数组。
//	return 0;
//}

/*
	关于集合
		1.数组：一组相同类型元素的集合。
		2.结构体：结构体同样是一些值的集合，但值的类型可以不相同。
*/

/*
	结构体
		1.结构体类型的声明
			a.结构体是一些值的集合，这些值称为成员变量；结构体内的每个成员可以是不同类型的变量。
			b.结构体内的成员可以是标量、数组、指针，甚至是其他结构体。
		2.结构体初始化
		3.结构体成员访问：使用操作符“.”以及“->”达到结构体访问成员名。
		4.结构体传参
			a.函数传参的时候，参数是需要压栈的(栈：一种数据结构，先进的后出，后进的先出，类似电梯)。
			b.若传递的结构体对象过大，参数压栈的系统开销比较大，会导致性能的下降。
			c.结构体传参时，需传结构体的地址。
*/

////结构体示例
//struct Privacy//声明一个类型“Privacy”。
//{
//	char Sexual_orientation[5];//性取向。
//	char Phone_number[20];//手机号。
//};
//
//struct Student//声明一个类型“Student”。
//{
//	//以下为成员变量的声明。
//	char name[10];//名称。
//	int age;//年龄。
//	char id[20];//学号。
//	struct Privacy A;//隐私；包含了结构体类型“Privacy”。
//}A1, A2;//创建结构体对象的第一种方式：使用“Student”类型创建“A1”和“A2”对象，这两个变量为全局变量。
//
//void print(struct Student B1_A, struct Student* B1_B)
//{
//	printf("\n%s %d %s %s %s\n", B1_A.name, B1_A.age, B1_A.id, B1_A.A.Sexual_orientation, B1_A.A.Phone_number);
//	printf("\n%s %d %s %s %s\n", B1_B->name, B1_B->age, B1_B->id, B1_B->A.Sexual_orientation, B1_B->A.Phone_number);
//}
//
//int main()
//{
//	//如下为创建结构体对象的第二种方式：使用“Student”类型创建“B1”对象并进行初始化，此变量为局部变量。
//	struct Student B1 = { "Aoki",19,"2020412505XX",{"保密","186XXXXXXXX"} };
//	
//	//如下是将“B1”的地址存放到结构体类型为“Student”的指针变量“pa”中。
//	struct Student* pa = &B1;
//	
//	//结构体成员访问(使用“.”操作符)
//	printf("%s\n", B1.name);
//	printf("%d\n", (*pa).age);
//	
//	//结构体成员访问(使用“->”操作符)
//	printf("%s\n", pa->id);
//	printf("%s\n", pa->A.Phone_number);//“->”操作符的左操作数应为指针变量。
//	printf("%s\n", pa->A.Sexual_orientation);
//
//	//结构体传参
//	print(B1, &B1);//参数“B1”是将结构体作为形参传递给了子函数(传值调用)；参数“&B1”是将结构体的地址传递给了子函数(传址调用)。
//
//	return 0;
//}