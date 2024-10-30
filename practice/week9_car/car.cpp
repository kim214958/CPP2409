// car헤더파일 호출
#include "car.h"

// Car 인터페이스의 getSpeed()함수 구현
int Car::getSpeed(){
    return speed;
}
// Car 인터페이스의 ㄴetSpeed()함수 구현
void Car::setSpeed(int s){
    speed = s;
}