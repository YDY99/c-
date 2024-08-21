

//학습 목표 : C언어 포인터 C++에서 활용법, 참조자(Reference)에 대한 이해



#include "lectures.h"
#include <cstdio>  // iostream
#include <cstring> // string

/*
*  C언어에서 포인터를 사용하는 이유?
*  함수를 사용하면서 함수 안에서 데이터를 변경하려면 포인터를 인자로 넘겨줘야 했습니다.
*/

/*
*  함수을 사용할 때 포인터가 아닌 참조자를 사용하면 인자로 &(주소연산자를) 사용하지 않을 수 있다.
*  주소 선언   : int*
*  참조자 선언 : int& 참조자 이름 = 참조하고자 하는 변수;
*  int a;
*  int&	AnotherA = a;
*/

void SwapInt(int* a, int* b)	 // 함수를 이용해서 값을 변경하기 위해서는 포인터를 사용해야한다.
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 함수 오버로딩 : C언어는 함수의 이름으로 함수를 구별합니다. 그런데, C++ 함수의 이름 + (매개변수, 인자)
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void ChangeVal(int& p)
{
	// p의 값을 10으로 변경하는 코드를 작성해 보세요
	p = 10;
}


int Function()  // int를 반환하는 함수.
{
	int a = 2;
	return a;
}

// 참조자를 리턴하는 함수
// 사용하지 않도록 쓰이는 예시.
int& Function2()
{
	int a = 2;
	return a;
}

int& Function3(int& a)
{
	a = 2;
	return a;
}

typedef struct Human
{
	char name[30];  // 이순신
	int age;		// 30
}Human;

// 정수형 레퍼런스를 반환하는 함수를 하나 만들어 주세요.
// Human 구조체를 레퍼런스로 반환하는 함수를 하나 만들어 주세요.
// 
// Human 데이터를 넣는 함수.
void AddHumanInfo(Human& human)
{
	// cin 함수를 이용해서 이름 받아오기 

	strcpy_s(human.name, 30, "이순신");
	// cin 함수를 이용해서 나이 받아오기
	human.age = 30;
}
void PrintHumanInfo(Human& human)
{
	std::cout << "이름 : " << human.name << std::endl;
	std::cout << "나이 : " << human.age << std::endl;
}


void lecture2()
{
	std::cout << "2강 " << std::endl;
	// 복습 C언어 포인트

	int num = 10; // num변수 10이라는 정수, 주소
	int* numPtr = &num;  // 포인터(변수);

	// C언어와 비교했을 때 C++는 데이터의 형태를 명시하지 않아도 작동한다.(편리하다.)
	printf("포인터의 주소 %p\n", numPtr);

	std::cout << "포인터의 주소 : " << numPtr << std::endl;
	std::cout << "포인터가 가리키는 값 : " << *numPtr << std::endl;

	// 변수의 이름 규칙
	//int number_of_people; // 단어와 단어사이를 '_' 표현하고 있습니다.
	//int NumberOfPeople;	  // 띄어쓰기 할 때 대문자로 표현한다. 

	// 주의해야할 사항. 두 방식을 같이 혼동해서 쓰지 말 것
	// 1. int NumerOfMonster; 변수의 이름 규칙을 하나로 통일해서 쓰는 것
	// 2. int number_ofPeople; 두 방식을 섞어서 쓰지 말 것

	int num1 = 1, num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1의 값 " << num1 << std::endl << "num2의 값 " << num2 << std::endl;

	// 참조자 만드는 법
	// 참조자 : 변수의 별명
	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1;  // AnotherA1은 a1의 별명이다.

	std::cout << "AnotherA1의 값 " << AnotherA1 << std::endl;

	// a1 쓰면 되는거 아닌가요?
	// -> Primitive type
	// 구조체의 크기는 사용자 정의형이기 때문에 작성자에 따라서 크기가 달라진다.
	// 참조자도 마찬가지로, 참조자가 가리키는 주소를 한번 복사하면 8바이트(64비트 시스템) 만으로 구조체를 복사해서 쓸 수 있다.

	// 참조자와 포인터가 다른 부분
	// 포인터는 주소연산자를 인자로 받게 해야한다. 사용자가 함수와 포인터에 대한 이해도가 있어야 한다. (C언어)
	// 참조자는 주소연산자를 인자로 받나요? 안받는다. 사용자가 더 편리한 문법이다. (C++언어)

	int c_num2;
	std::cin >> c_num2;
	std::cout << "c_num2의 값 " << c_num2 << std::endl;

	// 참조자(Reference) 함수에서 사용하는 방법

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num1의 값 " << d_num1 << std::endl << "d_num2의 값 " << d_num2 << std::endl;

	// 참조자는 반드시 선언과 동시에 초기화를 해야 합니다.
	// 참조자는 선언할 때 상대의 주소를 가져와서 복사를 한다.
	int& AnotherDNum1 = d_num1;

	// int& Literal = 100; // 참조자는 리터럴 상수를 가리키지 못한다.   
	const int& Literal = 100; // 참조자는 const 키워드를 통해서 상수를 가리킬 수 있게 된다.

	int p = 5;
	ChangeVal(p);
	std::cout << p << std::endl;

	// 참조자(레퍼런스)를 리턴하는 함수

	int p2 = 5;

	int tempA = Function();	// tempA Function안에 있는 a의 값을 복사해서 대입한다.
	int tempB = Function3(p2);

	// ★★ 레퍼런스 타입을 리턴할 때는 반드시 지역변수를 반환하지 않도록 조심해야 한다. ★★

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	// int& anotherTemp = Function(); // 
	const int& anotherTemp = Function();
	// int& anotherTemp2 = Function2(); // 일부 컴파일러에서 컴파일 에러가 발생합니다.

	// (1) 함수에서 값을 리턴할 때  int a = Function();
	// int a = Function();   a = 2; 2라는 값을 a에 대입한다. 값의 복사가 이루어졌다. 사용 가능
	// int&	a = Function();  참조자 타입으로 리터럴 상수를 가르킬 수 없다. 컴파일에러가 발생한다.
	// const int& a = Function(); 참조자가 리터터를 가리키게 하고 싶으면 const 키워드를 사용한다. 
	// 단, const 수식 받는 a 참조자는 값의 변경이 불가능하다.

	// (2) 함수가 참조자를 리턴할 때 int& Function();
	// ★★ 레퍼런스 타입을 리턴할 때는 반드시 지역변수를 반환하지 않도록 조심해야 한다. ★★

	Human human;

	AddHumanInfo(human);
	PrintHumanInfo(human);
}