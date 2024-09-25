#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL)); // random 함수 관련 설정

    int answer = rand()%100; // 정답 (0~99)
    int tries = 1; // 시도 횟수 (처음 입력도 횟수로 포함)
    int guess; // 정답 시도
 
    do {
        cout << "숫자를 입력하세요: ";
        cin >> guess;  // 사용자 입력 받기

    

        if(guess!=answer){// 오답이면 힌트 제공
        cout<<"오답입니다. 다시 시도하십시오."<<endl;
        tries++;
            if(guess>answer)
            cout<<"제시한 숫자가 큽니다."<<endl;
            else
            cout<<"제시한 숫자가 작습니다."<<endl;
        }

    } while (guess != answer);// 정답이 아니면 반복 실행


    cout << "축하합니다. 시도 회수=" << tries << endl;
    return 0;
}