#include <iostream>
using namespace std;

class Circle{
    public: // 접근제어자 public
        int x,y;
        int radius;
        Circle() { x = 0; y = 0; radius = 0;} // 기본 생성자
        Circle(int x, int y, int r) { this->x = x; this->y = y; this->radius = r;} // x,y,r 설정하는 생성자 this는 객체 내부의 변수를 참조
        void Print() { // 반지름과 x,y좌표를 프린트하는 함수
        cout << "반지름: " << radius << " @(" << x << ", " << y <<")" << endl;
    }
};

int main(void){
    Circle objArray[10]; // Circle 객체 10개를 배열로 생성
    for (Circle& c: objArray) { // 배열 내부의 Circle 객체에 대해서 
    // x, y, radius를 무작위로 설정 (x:0~500), (y:0~300), (radius:0~100)
    c.x = rand()%500;
    c.y = rand()%300;
    c.radius = rand()%100;
    }
    for (Circle c: objArray) // 배열 내부의 Circle객체의 Print 함수를 호출
    c.Print();
    return 0;
}   