#include <iostream>
#include "GameObjects.h"

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


int main(void)
{
	std::cout << "RPG BATTLE SYSTEM" << std::endl;

	Player player(100, 10);
	//player.Attack(); 공격 기능 제한
	player.BeAttacked(10); // 100 - 10 = 90

	Item sword("소드", 10);
	Reward slimeReward(50, 1000, sword);
	Slime slime(50, 5, &slimeReward);

	int userInput = 0;
	int turn = 1;

	while (true)
	{
		std::cout << "현재 진행 중인 턴 수 : " << turn << std::endl;
		std::cout << "1번. 공격" << std::endl;
		std::cout << "2번. ??" << std::endl;
		std::cin >> userInput;
		if (userInput == 1)
		{
			player.Attack(&slime);
		}

		std::cout << "슬라임의 Turn" << std::endl;
		slime.Attack(&player);

		if (player.IsDead() || slime.IsDead())
		{
			break;
		}

		turn++;
	}

	// 1. 게임 시작 화면

	// 2. 메인 게임 플레이

	// Phase 1. Map Adventure (맵을 돌아다니는 기능) ( Step++ RandomEncount : SRand( 5 ~ 25)) 
	// 특정 타일을 밟으면 몬스터랑 조우할지 안할지 랜덤 함수를 돌린다.

	// Phase 2. Player vs Monster (몬스터를 하나 만들고, 그 몬스터 같지만 다른 varitaion된 몬스터를 구현) 

	// player 객체 생성	      Initialize
	// monster 객체 생성
	// monster Reward 객체
	// Reward Item 객체

	// while(true) { }
}