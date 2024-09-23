#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;
    

    cout << "3개의 정수를 입력하시오: " <<endl;
    cin >> a >> b >> c;

    //a,b,c가 같은 값이면 기존의 식에서 오류 발생, 해결하기 위해 조건문에 등호를 추가

        // a가 b,c보다 크거나 같으면 largest는 a이다.
        if(a>=b&&a>=c){
        largest = a;
    }
        // b가 a,c보다 크거나 같으면 largest는 b이다.
     else if (b>=a&&b>=c){
        largest = b;
    }
        // c가 a,b보다 크거나 같으면 largest는 c이다. 또는 a,b,c값이 모두 같으면 largest = c이다.
     else
        largest = c;
    
    cout << "가장 큰 정수는" << largest <<endl;




    return 0;
}