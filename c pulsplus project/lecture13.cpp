#include "lectures.h"

/*
*  template 키워드
*  코드를 위한 틀을 만드는 것.(데이터 타입)
*/
class One;

template <typename T>
void Plus(T a, T b)
{
	std::cout << a << "+" << b << " : " << a + b << std::endl;
}

template <typename T1, typename T2>
void SomeFunc(T1 a, T2 b) {}

template <typename T1>
void SomeFunc(T1 a, int b) {}

class One
{
public:
	void operator+(const One& one)
	{
		std::cout << " a + b의 연산자 오버로딩 출력" << std::endl;
	}
};

template <typename T>
class Point
{
private:
	T posX;
	T posY;
public:
	Point() {}
	Point(T x, T y) : posX(x), posY(y) {}
	void Show()
	{
		std::cout << "pos X : " << posX << std::endl;
		std::cout << "pos Y : " << posY << std::endl;
	}
};

/*
*  클래스 템플릿과 함수 템플릿의 차이점
* - 함수 템플릿은 함수를 호출 시에 <type> 명시하지 않으면 (인자)를 통해서 타입을 유추한다.
* - 묵시적으로 템플릿 함수를 선언한다. 일반 함수가 존재한다면, 일반 함수가 먼저 실행이 된다.
* - 클래스 템플릿은 묵시적으로 타입을 지정해주는 기능이 없다.
*/


// non type teplate<typename T, int VAL>

template <typename T, int N>
class MyArray // 우리가 직접 만드는 배열
{
private:
	T data[N]; // size 크기 만큼 배열을 선언하겠다.

public:
	MyArray() {}
	MyArray(T(&arr)[N]) // 배열을 복사해서 저장하는 생성자
	{
		for (int i = 0; i < N; i++)
		{
			data[i] = arr[i];
		}
	}

	T* GetArray() { return data; }
	int Size() { return N; }

	void ShowInfo()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << data[i] << ",";
		}
		std::cout << std::endl;
	}

	// 연산자 오버로딩 [] 
};

/*
*  C, C++ << 언리얼 엔진, 클래스 만드는 법. 객체 지향 프로그래밍.
*  추상화 : 현실에 존재하지 않는 것도 코드로 표현하는 것
*  정보 은닉, 캡슐화 => 프로그래머 실수를 방지.
*  다형성 : Play();  dynamic_cast<Dog*>
*  STL << Standard Template Library
*  - 안전성이 보장이 된다.
*  - Template : 데이터 타입을 모두 대응하는 일반화 프로그래밍.
*  Vector<Item>. 가변 배열 << 자료 구조
*/

// 플레이어 <-> 몬스터 배틀 시스템  (player - monster)
// GameManager 클래스를 만들어보자.  
// 기능 : 배틀 종료. 점수 시스템. 저장. 종료. 시작. 불러오기.

//GameManager GM;	 // 점수, 저장
//GameManager GM2; //	시작, 종료
// 클래스가 한개만 존재해야 하는 패턴화 - 싱글톤 패턴
// template 클래스를 표현하면 -> 싱글톤 패턴이 필요한 클래스를 모두 사용할 수 있다.
// 상속 + 템플릿 클래스

template <typename T>
class SingleTon
{
	// 반드시 객체가 하나만 있어야 한다.
private:
	static T* singleTon;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleTon()
	{
		if (nullptr == singleTon)
		{
			singleTon = new T;
		}
		return singleTon;
	}

	static void Release()
	{
		delete singleTon;
		singleTon == nullptr;
	}
};

template <typename T>
T* SingleTon<T>::singleTon = nullptr;

class GameManager : public SingleTon<GameManager>
{
private:
	int score;

public:
	GameManager() {}
	~GameManager() {}
	GameManager(int s) : score(s) {}
	int GetScore() { return score; }
	void SetScore(int val) { score = val; }

	// 게임 시작, 게임 종료, 게임 저장...
	void GameStart()
	{
		std::cout << "게임 시작" << std::endl;
	}

	void GameEnd()
	{
		std::cout << "게임 종료" << std::endl;
	}

	void GameSave()
	{
		std::cout << "게임 저장" << std::endl;
	}
};

// GameData. 플레이 타임. 현재 진행중인 챕터. 

class GameData : public SingleTon<GameData>
{
private:
	int areaInfo; // 1번 1번지역....
public:
	GameData() {}

	int GetAreaInfo() { return areaInfo; }
	void SetAreaInfo(int area) { areaInfo = area; }
};


void lecture13()
{
	Point<int> p1(1, 2);
	p1.Show();
	Point<float> p2(1.1, 2.2);
	p2.Show();

	// 배열
	int arrNum[3] = { 1, 5, 9 };
	MyArray<int, 3> mArray(arrNum);
	std::cout << "MyArray 클래스의 크기 : " << mArray.Size() << std::endl;
	mArray.ShowInfo();

	double arrDouble[5] = { 1.1, 2.2, 3.3, 4.4 ,5.5 };
	MyArray<double, 5> arrD(arrDouble);
	arrD.ShowInfo();

	std::cout << "GameManager 클래스" << std::endl;

	GameManager* gm = GameManager::GetSingleTon();
	gm->SetScore(100);
	GameManager* gm2 = GameManager::GetSingleTon();
	gm2->SetScore(150);
	std::cout << gm->GetScore() << std::endl;

	// 게임 시작
	gm->GameStart();
	// 게임 메뉴

	// 메인 플레이

	// 종료
	gm->GameEnd();

	GameData* gameData = GameData::GetSingleTon();
	gameData->SetAreaInfo(10);
	std::cout << gameData->GetAreaInfo();

	GameData* gameData2 = GameData::GetSingleTon();
	std::cout << gameData2->GetAreaInfo();
}