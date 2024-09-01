#include "lectures.h"

/*
*  클래스 상속
*  1. class Parent{};
*  2. class Child : public Parent{}

*  class Pet
*  hungry, happy
*
*  dog, cat, bird... 추가 컨텐츠 :Pet 클래스 상속 받는 클래스 구현
*/

// 몬스터 : 추상적인 개념의 객체
// Gobllin..(인간형), -> 몬스터 상속받게 만든다.

/*
*  객체 포인터 참조관계
*  c++에서 포인터 변수는 해당 객체를 직접 혹은 간접적으로 가르킬 수 있다.
*  Dog : public Pet
*  Pet* pet; : 당연히 된다.
*  Pet* dog; : 상속된 클래스를 부모 포인터가 가르킬 수 있다.
*  Dog* dog;
*  Dog* pet; // 컴파일 에러 : 문법적으로 자식 클래스 포인터가 부모 클래스를 직접 가르키는 것을 막아두었다. -> 형변환
*  (Pet)Dog
*/

/*
*   정리 : 클래스의 확장성에 대한 문제를 개선하기 위한 방안1. <-> 시간
*   Dog클래스. Cat클래스도 Play(Dog* dog) Play(Cat* cat), Feed 함수로 표현
*   Cat과 Dog를 동시에 상속하는 Pet클래스를 인자로 넘겨준다.
*   Play(Pet* pet)  <- Dog
*/

/*
*  부모 클래스를 인자로 사용해서 범용성 있는 함수를 구현하였다.
*  void Play(Pet* pet)  => pet을 상속받는 모든 클래스를 범용적으로 표현가능하게 함.
*  문제가 발생했다. pet을 상속받는 Dog, HuntDog 자식 클래스와 부모 클래스가 같은 함수를 구현을 했는데,,
*  => 부모가 갖고 있는 함수를 자식 버전으로 변경하고 싶다.
*  가상 함수,  override 키워드
*  virtual 키워드 => 가상 함수
*  override 키워드 => virtual과 함께 사용된다. 덮어쓰다.
*/

/*
*   Pet*     a  = Pet; (o)
*   Pet*     b = dog;  (o)
*   Pet*     c = hdog; (o)
*
*   Dog*     a  = Pet ; (X)
*   Dog*     b  = dog;  (o)
*   Dog*     c  = hdog; (o)
*
*   HuntDog* a = hdog;
*   HuntDog* b = dog; (x)
*   HuntDog* c = pet; (x)
*/

class Pet // 플레이어가 추상적인 대상으로 접근할 수 있는 객체
{
protected:
    int hungry;
    int happy;
public:
    Pet() {};
    Pet(int hungry, int happy) : hungry(hungry), happy(happy)
    {
        std::cout << "Pet을 생성했습니다." << std::endl;
    }
    void ShowInfo()
    {
        std::cout << "배고픔 : " << hungry << std::endl;
        std::cout << "행복도 : " << happy << std::endl;
    }

    virtual void PlayWithMaster()
    {
        std::cout << "펫과 놀아주었다" << std::endl;
        hungry -= 10;
        happy += 5;
    }
};

class Dog2 : public Pet
{
public:
    Dog2() {}
    Dog2(int hungry, int happy) : Pet(hungry, happy)
    {
        std::cout << "개를 생성했습니다." << std::endl;
    }

    void PlayWithMaster() override // virtual 함수로 작성된 함수가 있으면 반드시 이 함수로 override해라
    {
        std::cout << "개와 놀아주었다." << std::endl;
        hungry -= 10;
        happy += 5;
    }
};

// Is- A 사냥개는 개이다.
class HuntDog : public Dog2
{
public:
    HuntDog() {}
    HuntDog(int hungry, int happy) : Dog2(hungry, happy) {}
    void Hunting();

    //void PlayWithMaster() override
    //{
    //    std::cout << "사냥개와 놀아주었다." << std::endl;
    //    hungry -= 20;
    //    happy += 10;
    //}
};

class Cat : public Pet
{

};

// PetController, PetHandler : Pet클래스를 제어하는 클래스다.
// pet과 놀아주다. Pet에 먹이를 주다.

class PetController // 펫관리자는 펫이다.(IS-A X), (Has-A o)
{
private:
    Pet* myPet;
    int money;   // 펫 먹이 비용, 알바를 통해서 돈 획득, 새로운 펫 구입
    int ActivePoint; // 행동력

    void UseActivePoint()
    {
        std::cout << "행동력을 1 소모했습니다." << std::endl;
        ActivePoint--;
        std::cout << "남은 행동력: " << ActivePoint << std::endl;
    }

public:
    PetController() {};  // 기본(디폴트) 생성자
    PetController(Pet* pet, int money, int AP) : money(money), ActivePoint(AP)
    {
        myPet = pet;
    }

    void EarnMoney(int pay) // 행동력을 소모해서 돈을 획득하는 함수
    {
        std::cout << pay << "만큼 돈을 획득했습니다." << std::endl;
        UseActivePoint();
        money += pay;
    }

    void Play()
    {
        myPet->PlayWithMaster();
        UseActivePoint();
    }

    void ShowInfo()
    {
        std::cout << "소지 금액 : " << money << std::endl;
        std::cout << "남은 행동력 : " << ActivePoint << std::endl;
        std::cout << "------펫의 정보------" << std::endl;
        myPet->ShowInfo();
    }
};

void lecture9()
{
    Pet pet(100, 100);
    Dog2 dog(100, 100);
    HuntDog huntDog(100, 100);
    PetController player(&pet, 1000, 3);
    player.Play();
    player.ShowInfo();

    PetController p2(&dog, 1000, 3);
    p2.Play();
    p2.ShowInfo();

    PetController p3(&huntDog, 1000, 3);
    p3.Play();
    p3.ShowInfo();
}