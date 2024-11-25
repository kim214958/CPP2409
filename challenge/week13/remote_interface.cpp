#include <iostream>
using namespace std;

class RemoteControl // 인터페이스 선언
{
public:
    // 순수 가상함수 선언
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television : public RemoteControl // 인터페이스를 상속
{
public:
    // 순수 가상함수 재정의
    void TurnON() override
    {
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override
    {
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl
{
public:
    // 순수 가상함수 재정의
    void TurnON() override
    {
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override
    {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main()
{   
    // 상향 형변환 객체생성
    RemoteControl *remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    // 상향 형변환 객체생성
    RemoteControl *remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();
}