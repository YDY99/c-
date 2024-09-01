#include "lectures.h"

// Pet 클래스
// Dog, HuntDog, Cat : Pet을 상속하는 클래스
// (down, child, derived) //  (up, parent, base) 

// PetController Handler 클래스
// Has-A. Feed(Pet* pet) Play(Pet* pet)
// 
// 1. 확장성의 문제점 
// Play(Dog, Cat, Bird...) 확장해야 하는 클래스 만큼 오버로딩을 해야하는 문제
// 1-2 해결 방안
// Play(Pet* pet) -> Pet 클래스 안에 있는 virtual void PlayWithMaster();
// virtual - override 

// 클래스 상속과 생성자

// 클래스 포인터와 상속 관계
// First 클래스 타입
// Second 클래스 타입 ( First 클래스 + Second 고유 멤버)

// First* a = new First();
// First* b = new Second();

// Second* b = new Second();
// Second* a = new First();  // 안될 가능성이 있기 때문에 문법적으로 막았다.

// Casting(형변환)

class First
{
private:
	char* str1;
public:
	First(const char* _str1)
	{
		str1 = new char[strlen(_str1 + 1)];
		strcpy_s(str1, strlen(str1), _str1);
	}
	virtual void SimpleFunc()
	{
		std::cout << str1 << std::endl;
	}
};

class Second : public First
{
private:
	char* str2;
public:
	Second(const char* _str1, const char* _str2) : First(_str1)
	{
		str2 = new char[strlen(_str2 + 1)];
		strcpy_s(str2, strlen(str2), _str2);
	}
	void SimpleFunc() override
	{
		std::cout << str2 << std::endl;
	}
};





class Handler
{

};

// c언어 형변환   (타입) 이름;
	// c++언어 형변환 조건을 추가해서 연산자로 만듦.
	// static_cast, dynamic_cast, reinterpret_cast, const_cast

// 1. static_cast 연산자    (static : 정적인)
// 2. dynamic_cast 연산자	 (dynamic : 동적인)

// 첫번째. 기본 데이터 타입(primitive Type) : int, double, char 들의 형변환은 무조건 static_cast 사용하라

class Water
{
private:
	int mL;
public:
	Water(int mL) : mL(mL) {}
	virtual void Show()
	{
		std::cout << mL << "mL" << std::endl;
	}
};

class SparklingWater : public Water
{
private:
	int sparkle;
public:
	SparklingWater(int mL, int sparkle) : Water(mL), sparkle(sparkle) {}
	void Show() override
	{
		Water::Show();
		std::cout << sparkle << std::endl;
	}
};

// 포인터, 참조자 사이의 형변환 연산자
// reinterpret_cast


/*
*  <<c++ 형변환 연산자 정리>>
* - 기본 자료형의 형변환은 static_cast를 사용하라.
* - 상속관계에서 형변환은 dynamic_cast를 사용하라.
* - 상속관계에서 강제로 형변환을 해야하는 경우에는 static_cast를 사용하라.
* - 포인터/참조 타입에서 무조건 형변환을 강제 시키려면 reinterpret_cast를 사용하라
* - const 성향을 없애려면 const_cast를 사용하라
*/


void lecture10()
{
	std::cout << "10강. 객체 지향프로그래밍 다형성" << std::endl;
	First* fptr = new First("첫번째 클래스");
	fptr->SimpleFunc();

	First* sPtr = new Second("첫번째 클래스", "두번째 클래스");
	sPtr->SimpleFunc();

	// 1번 예시 static_cast
	std::cout << "static_cast 기본 형변환" << std::endl;
	int d = 4;
	char* iPtr1 = (char*)&d; // c스타일 형변환

	// reinterpret_cast 예시
	// 용도 : 포인터, 참조자 사이의 형변환을 강제로 실행시킨다.
	// parent* child*
	char* iPtr2 = reinterpret_cast<char*>(&d);
	First* sptr2 = reinterpret_cast<First*>(fptr);

	// const_cast 연산자
	// 상수 키워드로 선언한 변수를 비 상수로 변경하는 연산자.
	const char* str = "Hello"; // ROM에 저장되어 있기 때문에
	char* str2 = const_cast<char*>(str);  // const_cast로 형변환을 했어도
	//주의 사항 str2[2] = 'a'; // str2직접 접근해서 변경하는 것은 불가능 하다.
	std::cout << "const_cast 예시 : " << str2 << std::endl;

	int newint = static_cast<int>(d);  // 사용 가능한 경우

	// static_cast를 사용하는 이유
	// 1. 강제 형변환을 아래 조건으로 제한하고 있다.
	// 다른 타입 간의 형 변환 제한한다. (int <-> double <-> char)

	// 2. 부모<->자식 클래스 형변환
	// Parent* parent = new Child();
	// (Child)parent;

	// dynamic_cast 연산자
	// 상속관계에서의 형변환을 안전하게 처리할 수 있는 연산자
	// static cast의 경우에는 형변환이 불가능한 경우에도 컴파일을 허용하기 때문에 
	// 상속관계에서 불안전한 형변환 방식이다.
	// dynamic_cast 사용해야 한다.

	std::cout << "부모 자식 형변환 예시" << std::endl;

	// 부모 클래스 자식 클래스로 형변환하라
	Water* water = new SparklingWater(100, 10);
	water->Show();


	// static_cast -> dynamic_cast 변환
	SparklingWater* spWater = dynamic_cast<SparklingWater*>(water); 	 // 부모 포인터(탄산수가 들어있는 객체)
	spWater->Show();
	Water* water2 = new Water(150);
	SparklingWater* spWater2 = dynamic_cast<SparklingWater*>(water2); // 부모 포인터(부모 객체)가 들어 있다.
	if (spWater2 != nullptr)
		spWater2->Show();

	// spWater2를 static_cast로 형변환하면 그대로 컴파일 에러가 발생한다.
	// spWater2를 dynaic_cast로 형변환을 해서 그 결과값이 형변환이 불가능하면 nullPtr를 반환한다.

	// Pet Dog Cat..     
	// Cat* catPtr = dynamic_cast<Cat*>(myPet);
	// if(myPet != nullPtr)
	//		catPtr->Hide();
	// Dog*	dogPtr
}