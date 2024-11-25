#include "user.h"

// Magician 클래스 구현 User 객체의 함수를 override
Magician::Magician()
{
    hp = 10;
    item_cnt = 0;
}

int Magician::GetHP()
{
    return hp;
}

void Magician::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}

void Magician::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

void Magician::IncreaseCnt(int inc_cnt)
{
    item_cnt += inc_cnt;
}

void Magician::DoAttack()
{
    cout << "마법 사용" << endl;
}


// Warrior 클래스 구현 User 객체의 함수를 override
Warrior::Warrior()
{
    hp = 10;
    item_cnt = 0;
}

int Warrior::GetHP()
{
    return hp;
}

void Warrior::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}

void Warrior::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

void Warrior::IncreaseCnt(int inc_cnt)
{
    item_cnt += inc_cnt;
}

void Warrior::DoAttack()
{
    cout << "베기 사용" << endl;
}
