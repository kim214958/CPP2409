#include <iostream>
using namespace std;

class Dog { // Dog 클래스
    private: // 접근제어자 pritvate
        int *pWeight; // 포인터 변수 pWeight
        int *pAge; // 포인터 변수 pAge
    public: // 접근제어자 private
        Dog() { // 나이를 1, 무게를 10으로 설정하는 기본 생성자
            pAge = new int(1);
            pWeight = new int(10);
        } 
        ~Dog() { // 포인터 변수의 메모라를 반납하는 소멸자
            delete pAge;
            delete pWeight;
        }
        // 나이와 무게를 설정하는 getter,setter
        int GetAge() { return *pAge; }
        void SetAge(int age) { *pAge = age; }
        int GetWeight() { return *pWeight; }
        void SetWeight(int weight) { *pWeight = weight; }
};

int main(){
    Dog *pDog = new Dog; // Dog 객체 생성
    cout << "강아지의 나이: " << pDog->GetAge() << endl;

    pDog -> SetAge(5);
    cout << "강아지의 나이: " << pDog->GetAge() << endl;

    delete pDog;
    return 0;
}