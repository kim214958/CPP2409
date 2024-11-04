#include <iostream>
using namespace std;

class Pizza {
    public:
    // 생성자 선언
    Pizza(int s) : size(s) { }
    int size; // 단위: 인치
};

void MakeDouble(Pizza& p) { // 객체의 참조자가 매개변수 전달
    p.size *= 2; // 전달된 참조자가*2 된다.
}

int main() {
    // Pizza 클래스인 pizza 객체 생성 ( size는 10)
    Pizza pizza(10);
    MakeDouble(pizza); // MakeDouble() 함수에 매개변수로 pizza의 참조자가 전달
    cout << pizza.size << "인치 피자" << endl; // pizza 객체의 size 확인
    return 0;
}