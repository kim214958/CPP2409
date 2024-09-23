#include <iostream>
using namespace std;

int main(){
    int number;
    //숫자를 입력받음
    cout << "숫자를 입력하시오:";
    cin >> number;

    //숫자에 따라 아래의 값을 출력
    switch (number){
    case 0:
        cout <<"zero"<< endl;
        break;
    case 1:
        cout <<"one"<< endl;
        break;
    default:
        cout <<"many"<< endl;
        break;
    }
    
}