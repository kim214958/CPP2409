#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int i ;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다." << endl;

    while(true){//덧셈할 숫자 2개를 랜덤으로 생성
        int firstNum = rand()%100;
        int secondNum = rand()%100;
        //문제 출력
        cout<<firstNum<<" + "<<secondNum<<" = ";
        cin>>ans;
        if(ans == (firstNum+secondNum)){// 문제와 정답 비교
            cout <<"정답입니다!"<<endl;
            break;// 정답이면 종료
        }
        else{
            cout <<"오답입니다."<<endl; 
            continue;//오답이면 재시도
        }
    }
    return 0;
}