#include <iostream>
#include <string>
using namespace std;

// 클래스 User 인터페이스 선언
class User
{
protected:	// 접근제어자 private
	int hp; // hp는 private이므로 getter를 통해서만 접근가능
	int item_cnt;

public:										 // 접근 제어자 public
	User() {};								 // 생성자
	virtual int GetHP() = 0;				 // hp를 반환하는 함수
	virtual void DecreaseHP(int dec_hp) = 0; // hp를 감소시키는 함수
	virtual void IncreaseHP(int inc_hp) = 0; // hp를 증가시키는 함수
	virtual void IncreaseCnt(int inc_cnt) = 0;
	virtual void DoAttack() = 0; // 순수 가상함수, 공격하는 함수
	friend ostream &operator<<(ostream &os, const User* &player)
    {
        os << "현재 HP는 " << player->hp << "이고, "
           << "먹은 아이템은 총 " << player->item_cnt << "개 입니다.";
        return os;
    }
};