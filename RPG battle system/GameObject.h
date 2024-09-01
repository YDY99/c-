#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>

// 몬스터와의 전투
// 1. 공격 - 공격력, 체력

class Item
{
private:
	std::string name;
	int index;
public:
	Item() {}
	Item(std::string name, int index) : name(name), index(index) {}
	void ShowItemInfo()
	{
		std::cout << "아이템의 이름 : " << name << std::endl;
		std::cout << "아이템의 번호 : " << index << std::endl;
	}
};

class Reward
{
private:
	int exp;
	int money;
	// 아이템
	Item* item;

public:
	Reward() {}
	Reward(int exp, int money, Item& item) : exp(exp), money(money)
	{
		this->item = new Item();
		this->item = &item;
	}
	~Reward()
	{
		delete item;
	}

	void RewardItem(std::vector<Item>* inventory);
	int RewardMoney() { return money; };
	int RewardExp() { return exp; };
};


class Monster;

class Player
{
private:
	int HP;
	int AP;
	// 체력, 공격력
	int exp;
	int money;
	std::vector<Item> inventory; // 캐시템 아이템 인벤토리 확장권 팔겠다. 가변 배열 vector
public:
	// 생성자
	Player() {} // 기본 생성자
	Player(int hp, int ap) : HP(hp), AP(ap)
	{
		std::cout << "플레이어가 생성됨" << std::endl;
	}
	// 소멸자
	~Player() // 동적할당을 했을 때 delete
	{
		std::cout << "플레이어가 소멸됨" << std::endl;
	}

	// 공격하다
	void Attack(Monster* monster);
	// 공격받다.
	void BeAttacked(int damage);
	// 사망 체크 함수
	bool IsDead();

	int GetAttackPower() { return AP; }
	void GetMoney(int money);
	void GetExp(int exp);
	std::vector<Item>* GetInventory();

	// 플레이어의 현재 스탯을 보여주는 함수
	void ShowStatus();
};

// 순수 가상 함수
class Monster
{
protected:
	int HP;
	int AP;
	// 보상
	Reward* monsterReward;

public:
	// 생성자
	Monster() {}
	Monster(int hp, int ap) : HP(hp), AP(ap) {}
	// 소멸자
	~Monster() {}
	// Attack
	virtual void Attack(Player* player) = 0;
	// Be_Attacked
	virtual void BeAttacked(Player* player) = 0;
	// DropReward
	virtual void DropReward(Player* player) = 0;
};

class Slime : public Monster
{
public:
	Slime(int hp, int ap, Reward* rewardPtr) : Monster(hp, ap)
	{
		std::cout << "슬라임 생성!" << std::endl;
		InsertDropItemTable(rewardPtr);
	}
	~Slime()
	{
		std::cout << "슬라임 소멸됨!" << std::endl;
	}

	void InsertDropItemTable(Reward* rewardPtr)
	{
		monsterReward = new Reward();
		monsterReward = rewardPtr;
	}

	// Attack
	void Attack(Player* player);
	// Be_Attacked
	void BeAttacked(Player* player);
	// DropReward
	void DropReward(Player* player);

	// 사망 체크 함수
	bool IsDead();
};




