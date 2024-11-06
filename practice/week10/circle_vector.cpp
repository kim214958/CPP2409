#include <iostream>
#include <vector>
using namespace std;

class Circle{
    public:
    int x, y;
    int radius;
    Circle() { x = 0; y = 0; radius = 0; }
        Circle(int x, int y, int r) {
        this->x = x;
        this->y =y;
        this->radius = r;
    }
    void Print() {
        cout << "반지름: " << radius << " @(" << x << ", " << y <<")" << endl;
    }
};

int main(void){
    vector<Circle> objArray; // Circle 타입의 벡터 생성

    for (int i = 0; i < 10; i++) {
        // x, y, radius를 무작위로 설정 (x:0~500), (y:0~300), (radius:0~100)한 Circle 객체 obj를 생성
        Circle obj{ rand()%300, rand()%300, rand()%100 };
        objArray.push_back(obj); // 생성한 obj를 Cicle 타입의 벡터 objArray에 담는다.
    }
    for (Circle c : objArray) // objArray 벡터 내부의 Circle 타입의 객체에 대해서
        c.Print(); // Circle의 Print 함수 실행
    return 0;
}