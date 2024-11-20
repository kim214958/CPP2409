#include <iostream>
#include <string>
using namespace std;

// 클래스 User 인터페이스 선언
class User{
	private: // 접근제어자 private
		int hp; // hp는 private이므로 getter를 통해서만 접근가능
		int itemCnt;
	public: // 접근 제어자 public
		User(); // 생성자
		int GetHP(); // hp를 반환하는 함수
		void DecreaseHP(int dec_hp); // hp를 감소시키는 함수
		void IncreaseHP(int inc_hp); // hp를 증가시키는 함수
		void IncreaseCnt(int inc_cnt);
		void doAttack(); // 공격하는 함수
		friend ostream& operator<<(ostream& os, const User& user){
			os<< "현재 HP는"<<user.hp<<"이고,"<<"먹은 아이템은 총"<<user.itemCnt<<"개 입니다."<<endl;
			return os;
		}		
};