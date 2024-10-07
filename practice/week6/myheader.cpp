#include <iostream>
#include "myheader.h"
using namespace std;

// myheader.h 의 해더파일에 있는 sumation 함수 재정의
int summation(int value1, int value2){
    int sum = value1 + value2;
    return sum;
}