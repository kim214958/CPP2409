#include <iostream>
using namespace std;

#define WIDTH 9
#define HEIGHT 3

int main(){
    int table[HEIGHT][WIDTH]; // 3*9 2D배열
    int r,c; // 배열의 인덱스 변수

    for (r=0; r<HEIGHT; r++){
        for(c=0; c<WIDTH; c++){
            table[r][c] = (r+1)*(c+1); // 1단,2단,3단을  2D배열 table에 담는다.
        }
    }

    for (r=0; r<HEIGHT; r++){
        for(c=0; c<WIDTH; c++){
           cout<< table[r][c] << ", ";// table의 배열 요소들 출력
        }
        cout << endl; // 구구단 줄 바꿈
    }
}