#include <iostream>
#include <string>
using namespace std;

// Car 클래스 선언
class Car {
    public:
    // 멤버 변수 선언
    int speed; // 속도
    int gear; // 기어
    string color; // 색상
    // 멤버 함수 선언
    void SpeedUp() { // 속도 증가 멤버 함수
        speed += 10;
    }
    void SpeedDown() { // 속도 감소 멤버 함수
        speed -= 10;
    }
};

int main(){

    // Car클래스의 객체 생성
    Car myCar;

    // myCar의 속도,기어,색상 설정
    myCar.speed = 100;
    myCar.gear = 3;
    myCar.color = "red";

    cout <<"1st speed: " << myCar.speed << endl;
    // myCar객체의 SpeedUp 함수 호출
    myCar.SpeedUp();
    cout << "2nd speed: " << myCar.speed << endl;
    // myCar객체의 SpeedDown 함수 호출
    myCar.SpeedDown();
    cout << "3rd speed: " << myCar.speed << endl;

    return 0;

}