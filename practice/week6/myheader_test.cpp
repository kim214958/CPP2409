#include <iostream>
#include "myheader.h"
using namespace std;


int main(){
    // 합에 사용할 int값 2개
    int a = 2;
    int b = 3;
    // myheader의 summation 함수를 호출
    int value = summation(a,b);
    cout << value << endl;

    return 0;
}