#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;
    

    cout << "3개의 정수를 입력하시오: " <<endl;
    cin >> a >> b >> c;

    if(a>=b){ //a와 b를 비교
        if(a>=c){ //a가 b보다 크다면 a와 c를 비교
            largest =a;
        }
        else
            largest =c;
    }
    else
        if(b>=c){ //b가 a보다 크다면 b와 c를 비교
            largest = b;
        }
        else
            largest = c;

   
    
    cout << "가장 큰 정수는" << largest <<endl;




    return 0;
}