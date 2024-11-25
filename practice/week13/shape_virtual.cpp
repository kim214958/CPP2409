#include <iostream>
using namespace std;
class Shape
{
protected:
    int x, y;

public:
    Shape(int x, int y) : x(x), y(y) {}
    virtual void Draw() // 가상함수 Draw
    {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape
{
private:
    int width, height;

public:                               // 부모 클래스의 생성자 호출
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}

    void Draw() // Draw 재정의
    {
        cout << "Rectangle Draw" << endl;
    }
};

int main()
{
    Shape *ps = new Rect(0, 0, 100, 100);
    ps->Draw();

    delete ps;
    return 0;
}