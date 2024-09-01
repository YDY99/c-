#include "lectures.h"

/*
*   1. c++ casting 연산자 예시
*
*   2. virutal 가상 함수에 대한 이해[객체지향프로그래밍의 다형성]
*   pure virtual
*   abstract 클래스
*   vtable
*
*   3. monster class (Goblin, Slime class) - Player 전투
*   4. 전투 결과 Reward - monster죽었을 때 보상하는 아이템
*/

class AA
{
public:
	virtual void Show()
	{
		std::cout << "AA" << std::endl;
	}
};

class BB : public AA
{
public:
	void Show()
	{
		std::cout << "BB" << std::endl;
	}

	void MyBB()
	{
		std::cout << "MyBB" << std::endl;
	}
};

class CC : public AA
{
public:
	void Show()
	{
		std::cout << "CC" << std::endl;
	}

	void MyCC()
	{
		std::cout << "MyCC" << std::endl;
	}
};

//  2. virutal 가상 함수에 대한 이해[객체지향프로그래밍의 다형성]
//	pure virtual     : Pet _ void Sound(Pet* pet) 개, 고양이, 새 공통적인 부분을 Pet. 울음소리.
//  Pet 클래스 자체는 추상적인 개념이다. 
// 
// 
//	abstract 클래스
//	vtable

class NewPet
{
public:
	virtual void Sound() = 0; // 순수 가상 함수 -> NewPet을 상속받는 Dog, Cat Sound 실행시켜라

};

// 순수 가상 함수 pure virtual function
// 기능 : 반드시 오버라이딩 되어야 하는 함수
// 순수 가상 함수를 포함하고 있는 클래스 추상 클래스라고 정의합니다.
// 추상 클래스는 반드시 하나 이상의 상속이 필요하다.
// NewPet*
// NewPet np1;

// virtual 가상 함수는 상속하는 클래스를 모두 참조해서 사용할 수 있다.
// 모든 함수를 virtual 함수 (가상 함수) 선언해도 문제가 없지 않나요?

// virtual 키워드 입력하는 의미 : 입력하지 않으면 키워드가 작동하지 않는다.

// 왜 c++ 기본 형식으로 virtual이 선언되어 있지 않는가?
// virtual 내부적으로 vTable 공간을 생성합니다. vPtr;
// virtual 선언하지 않앗을 때 : 바로 해당 함수를 실행한다.

// 다형성이 필요할 때만 가상함수를 사용하는 것이 가장 최적화와 속도가 빠른 코드가 될 수 있다.
// virtual 모든 함수에 사용해도 문제가 없어 보인다.
// 메모리, 시간에 조금씩 영향을 끼치고 있었다.

// monster class - 추상 클래스로 표현을 한번 해봅니다.
// reward class - 경험치(int), 재화(int)(money), 아이템(아이템 번호, (Item)), Quest Item
// Is-A, Has-A

// player <-> monster battle System
// battle class.  public : bool End() : 플레이어가 죽엇을 때, 몬스터가 죽었을 때 , 플레이어가 도주 했을 때..
// 무한 반복(전투의 끝 bool)
// 1. playerTurn.  (1)공격, (2)방어, (3)도주 
// NextTurn
// 2. MonsterTurn (1)공격  

// 몬스터가 죽으면 monster Class  Has, Is => Reward Drop Item()
// Player.GetItem(monster* m1); 



class NewDog : public NewPet
{
public:
	virtual void Sound()
	{
		std::cout << "왈왈!" << std::endl;
	}

	virtual void Play()
	{
		std::cout << "놀다" << std::endl;
	}

	void DDD()
	{
		std::cout << "DDD" << std::endl;
	}
};

void lecture11()
{
	std::cout << "c++ casting 연산자" << std::endl;
	std::cout << "1. static_cast<type>" << std::endl;
	// 기본 자료형의 변환, 포인터 및 참조 변환, 상속 관계의 클래스 변환에 사용될 수 있다.

	double pi = 3.14; // 3
	int pi_int = (int)(3.14) - (0.14); // (int)3.14 => 3 - 0.14 = (int)2.xxxxxx =>2 
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int의 값 : " << pi_int << std::endl;
	std::cout << "pitint2의 값 : " << pi_int2 << std::endl;

	// 첫번째, 가상 함수를 이용하여 객체의 다형성 표현
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();

	AA* aPtr3 = new CC();
	// static_cast 상속관계의 클래스를 표현

	BB* bPtr1 = static_cast<BB*>(aPtr2);
	bPtr1->Show();
	bPtr1->MyBB();

	BB* bPtr2 = static_cast<BB*>(aPtr3); // aPtr3 BB* -> CC*
	bPtr2->Show();
	bPtr2->MyBB();

	// static_cast<Type> : 다음 객체는 무조건 Type형태로 형변환을 시킨다.

	// 상속 사이의 클래스의 형변환 dymamic_cast

	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if (cPtr1 != nullptr) // C언어 NULL #define NULL 0. 포인터 변수 0. 가리키는 주소가 없다. nullPtr
	{
		cPtr1->MyCC();
	}

	// const_cast : const 키워드를 수식받는 변수의 상수성을 없애는 변환.

	const int num = 10;

	int* nonConstNum = const_cast<int*>(&num);
	*nonConstNum = 12;
	std::cout << "num의 값 : " << num << std::endl;
	std::cout << "nonConstNum의 값 : " << *nonConstNum << std::endl;

	// reinterpret_cast

	// int 65 = 0 0 0 00001000(2)
	// char 65			01111111(2)	->A

	int num2 = 65; // int형 주소값 char 주소로 강제 형변환
	char* charPtr = reinterpret_cast<char*>(&num2);
	std::cout << "char 형태로 강제 형변환 : " << *charPtr << std::endl;

	// 데이터가 담겨있는 유실을 신경쓰지 않고 강제로 형변환.
	double* intPtrValue = reinterpret_cast<double*>(&num2);
	std::cout << "정수를 강제로 실수로 변환 : " << *intPtrValue << std::endl;


	NewPet* nP1 = new NewDog();
	nP1->Sound();

	NewDog* nD1 = dynamic_cast<NewDog*>(nP1);
	nD1->Play();
}


