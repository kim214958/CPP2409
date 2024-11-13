#include <iostream>
using namespace std;

class Complex {
    public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
        cout << "생성자 호출";
        Print();
    }
    ~Complex() {
        cout << "소멸자 호출";
        Print();
    }
    void Print() {
        cout << real << "+" << imag << "i" << endl;
    }
};
Complex Add(Complex &a1, Complex &a2){
    Complex temp;
    temp.real = a1.real + a2.real;
    temp.imag = a1.imag + a2.imag;
    return (temp);
}


int main(){
    Complex c1{ 1,2 }, c2{ 3,4 };
    Complex t;
    t = Add(c1, c2);
    t.Print();
    return 0;
}
