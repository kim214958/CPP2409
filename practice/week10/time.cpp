#include <iostream>
using namespace std;

// Time 클래스 생성
class Time {
    private:
    int hour; // 0-23
    int minute; // 0-59
    public:
    // 생성자 선언
    Time(int h, int m){
        hour = h; // hour에 매개변수 h의 값을 넣는다.
        minute = m; // minute에 매개변수 m의 값을 넣는다.
    };
    // 메소드 IncHour
    void IncHour(){
        SetHour(GetHour()+1); // GetHour 함수를 호출하여 hour값을 받고 +1한 값을 setHour로 넣어준다.
    };
    void Print(){
        cout <<GetHour()<<":"<<GetMinute()<<endl; // GetHour,GetMinute 함수로 시간, 분값을 받는다.
    };
    // 캡슐화
    int GetHour() { return hour; } // hour 값 반환
    int GetMinute() { return minute; } // minute 값 반환
    void SetHour(int h) { hour = h; } // hour 설정
    void SetMinute(int m) { minute = m; } // minute 설정
};

int main(){
    // 시간,분에 0을 넣은 Time 객체 a 생성
    Time a {0,0};

    // 객체 a 의 시간, 분 설정
    a.SetHour(6);
    a.SetMinute(30);
    // 객체 a의 Print()함수 호출 -> 시간:분 값이 출력된다.
    a.Print();
    return 0;
}
