#include <iostream>
using namespace std;

// Rectangle class 정의
class Rectangle {
    int width, height; // 넓이, 높이 설정
    public: // 접근제어자 public
    Rectangle(int w, int h); // 생성자
    int CalcArea(); // 넓이 계산 함수
};

Rectangle::Rectangle(int w, int h){ // Rectangle 클래스 내 생성자 구현
    // 매개변수의 값을 width,height에 넣어줌
    width = w;
    height = h;
}
int Rectangle::CalcArea(){ // Rectangle 클래스 내 메소드 구현
    return width*height; // 넓이*높이 반환
}

int main(){
    Rectangle r{3,4}; // Rectangle 객체 r 생성
    cout << "사각형의 넓이 : "<<r.CalcArea()<<endl; // r 객체의 CalcArea()함수 호출
    return 0;
}