#include <iostream>
using namespace std;

int main(){
    int x, y;

    //x에 값을 받음
    cout << "x값을 입력하시오: ";
    cin >> x;

    //y에 값을 받음
    cout << "y값을 입력하시오: ";
    cin >> y;


    //x가 y보다 크면 밑의 문장을 출력
    if (x>y)
        cout << "x가 y보다 큽니다." << endl;

    //x와 y값이 같으면 밑의 문장을 출력
    else if(x==y){
        cout << "x와 y는 같습니다." << endl;
    }
    
    //x가 y보다 작으면 밑의 문장을 출력
    else
        cout << "y가 x보다 큽니다." << endl;

    return 0;
}