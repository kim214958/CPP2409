
#include <iostream>
#include <string>
using namespace std;

// User 인터페이스 선언
class User
{
protected:
	int hp;
	int item_cnt;

public:
	User() {}
	virtual int GetHP() = 0;
	virtual void DecreaseHP(int dec_hp) = 0;
	virtual void IncreaseHP(int inc_hp) = 0;
	virtual void IncreaseCnt(int inc_cnt) = 0;
	virtual void DoAttack() = 0;
	// 유저 객체의 포인터로 인자를 받음
	friend ostream &operator<<(ostream &os, const User *user)
	{
		os << "현재 HP는 " << user->hp << "이고, "
		   << "먹은 아이템은 총 " << user->item_cnt << "개 입니다.";
		return os;
	};
};

// Magician 클래스 선언
class Magician : public User
{
public:
	Magician();
	int GetHP();
	void DecreaseHP(int dec_hp) override;
	void IncreaseHP(int inc_hp) override;
	void IncreaseCnt(int inc_cnt) override;
	void DoAttack() override;
};

// Warrior 클래스 선언
class Warrior : public User
{
public:
	Warrior();
	int GetHP();
	void DecreaseHP(int dec_hp) override;
	void IncreaseHP(int inc_hp) override;
	void IncreaseCnt(int inc_cnt) override;
	void DoAttack() override;
};
