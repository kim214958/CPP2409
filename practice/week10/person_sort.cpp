#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Person{
private:
    string name;
        int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    string GetName() { return name; }
    int GetAge() { return age; }
    // 이름과 나이를 print하는 함수 Print()
    void Print() {
        cout << name << " " << age << endl;
    }
};


bool Compare(Person &p, Person &q){
    // Compare가 true를 반환하면 첫번째가 두번째 앞에 위치
    return p.GetAge() < q.GetAge();
}

int main(){
    vector<Person> list; // Person 객체를 담는 벡터 list
    // list에 Person 객체를 담음
    list.push_back(Person("Kim", 30));
    list.push_back(Person("Park", 22));
    list.push_back(Person("Lee", 26));
    // 벡터 list를 나이 순으로 정렬
    sort(list.begin(), list.end(), Compare);
    // 리스트에 포함된 Person 객체의 Print 함수를 실행
    for (auto& e : list) {
        e.Print();
    }
    return 0;
}