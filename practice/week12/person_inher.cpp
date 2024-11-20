#include <iostream>
using namespace std;

class Person
{
protected:
    string address;
    string name; // 접근제어자 교체
};
class Student : Person
{
public:
    void SetAddress(string add)
    {
        address = add;
    }
    string GetAddress()
    {
        return address;
    }
    void SetName(string name){ this->name = name; } // 에러
};
int main()
{
    Student obj;
    obj.SetName("미수") ; // 에러
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;
    return 0;
}
