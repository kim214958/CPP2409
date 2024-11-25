#include <iostream>
using namespace std;

class Shape
{
protected:
    int x, y;

public:
    Shape(int x, int y) : x(x), y(y) {} // 생성자
    virtual void Draw() = 0; // 순수 가상함수
};

class Rect : public Shape
{
private:
    int width, height;

public:                                 // 부모의 생성자
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}
    void Draw() // 순수 가상함수 재정의
    { // 없으면 에러
        cout << "Rectangle Draw" << endl;
    }
};

int main()
{
    Shape *ps = new Rect(0, 0, 100, 100); // OK!
    ps->Draw();                           // Rectangle의 draw()가 호출된다.
    delete ps;
    return 0;
}
