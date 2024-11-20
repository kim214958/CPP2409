#include "user.h"

// User 클래스 구현
User::User(){ // 기본 생성자
	hp = 20; // hp를 20으로 설정
	itemCnt = 0;
};
int User::GetHP(){  // 캡슐의 getter
	return hp; // hp를 리턴
};
void User::DecreaseHP(int dec_hp){ // hp를 감소시키는 함수
	hp -= dec_hp; // 매개변수의 값만큼 hp를 감소시킨다.
};
void User::IncreaseHP(int inc_hp) { // hp를 증가시키는 함수
	hp += inc_hp; // 매개변수의 값만큼 hp를 증가시킨다.
}
void User::IncreaseCnt(int inc_cnt){ // itemCnt를 증가시키는 함수
	itemCnt += inc_cnt; // 매개변수의 값만큼 itemcnt를 증가시킨다.
}
void User::doAttack(){
	cout << "공격합니다" << endl;
}