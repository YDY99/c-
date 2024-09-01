#include "GameObjects.h"

void Player::Attack(Monster* monster)
{
    std::cout << "플레이어의 공격!" << std::endl;
    monster->BeAttacked(this);

    // monster->BeAttacked(AP);   : 몬스터가 공격을 받음

    // 몬스터의 죽음 : bool isDead()

    // 만약에 몬스터가 죽었으면 -> 보상(Reward)Has-A 몬스터(Monster)
    // monster->reward->GetExp, GetGold, GetItem
}

void Player::BeAttacked(int damage)
{
    std::cout << "플레이어가 데미지 : " << damage << "받음!" << std::endl;

    HP -= damage;

    // 만약에 플레이어 사망했다면 -> *게임 오버* 함수를 호출한다.
    if (IsDead())
    {
        HP = 0;
        std::cout << "플레이어가 사망하였습니다." << std::endl;
        exit(0);
        // GameManager->GameEnd() // ReturnLobby()
    }
}

bool Player::IsDead()
{
    if (HP <= 0) // 플레이어가 언제 죽나? HP <= 0
        return true;
    else
        return false;
}

void Player::GetMoney(int money)
{
    std::cout << "획득한 재화 : " << money << std::endl;
    this->money += money;
}

void Player::GetExp(int exp)
{
    std::cout << "경험치 획득 : " << exp << std::endl;
    this->exp += exp;
}

std::vector<Item>* Player::GetInventory()
{
    return &inventory;
}

void Player::ShowStatus()
{
    std::cout << "현재 체력 : " << HP << std::endl;
    std::cout << "현재 공격력 : " << AP << std::endl;
    std::cout << "현재 경험치 : " << exp << std::endl;
    std::cout << "====플레이어 소지품====" << std::endl;
    std::cout << "현재 금액 : " << money << std::endl;
    // 반복문. 아이템의 최대 수. Item 배열[i] -> 아이템 이름, 아이템 번호, 기능..
    std::cout << "현재 아이템 : " << "함수로 구현(미구현)" << std::endl;
}

void Slime::Attack(Player* player)
{
    std::cout << "슬라임의 공격!" << std::endl;
    player->BeAttacked(AP);
}

void Slime::BeAttacked(Player* player)
{
    std::cout << "슬라임이 움츠러들었다" << std::endl;
    HP -= player->GetAttackPower(); // player->AP   // return player.AttackPower;

    if (IsDead())
    {
        HP = 0;
        std::cout << "슬라임을 처치했습니다." << std::endl;

        // 아이템 보상
        DropReward(player);
    }
}

void Slime::DropReward(Player* player)
{
    std::cout << "몬스터 처치 보상 " << std::endl;
    monsterReward->RewardExp();
    monsterReward->RewardMoney();
    monsterReward->RewardItem(player->GetInventory());
}

bool Slime::IsDead()
{
    if (HP <= 0)
        return true;
    else
        return false;
}

void Reward::RewardItem(std::vector<Item>* inventory)
{
    if (item != nullptr) // 아이템이 있을 경우에만 플레이어 inventory에 추가하기 위한 조건
    {
        inventory->push_back(*item);
        std::cout << "아이템 획득!" << std::endl;
        item->ShowItemInfo();
    }
}

