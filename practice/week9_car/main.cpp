//car 헤더파일 호출
#include "car.h"


int main(){
    // Car클래스의 객체 생성
    Car myCar;
    // Car클래스의 함수 호출
    myCar.setSpeed(80);
    cout << "현재 속도는 " ;
    cout << myCar.getSpeed();
    return 0;
}