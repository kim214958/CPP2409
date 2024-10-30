#include <iostream>
using namespace std;

// 사각형 클래스 선언
class Rectangle{
    public: // 접근제어 public
        int width, height; // 멤버 변수 넓이, 높이
        int CalcArea(){ // 멤버 함수 넓이계산 메소드
            return width * height;
        }
};

int main(){
    //Rectangle 클래스의 객체 생성
    Rectangle obj;
    Rectangle obj2;
    // 첫번째 객체의 멤버 변수에 값 저장
    obj.width = 3;
    obj.height = 4;
    // 첫번째 객체의 멤버 함수를 호출를 통해 변수 설정
    int area = obj.CalcArea();

    // 두번째 객체의 멤버 변수에 값 저장
    obj2.width = 10;
    obj2.height = 10;
    // 두번째 객체의 멤버 함수를 호출를 통해 변수 설정
    int area2 = obj2.CalcArea();

    cout << "사각형의 넓이 : "<< area <<endl;
    cout << "두번째 사각형의 넓이 : "<< area2 << endl;

    return 0;
}