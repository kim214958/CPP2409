#include <iostream>
using namespace std;

int main(){
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";

   for(int i = 0; i<10; i++){ //최대 10번까지 입력가능함
     cin >> userInput;
        if(userInput == 0){ // 0을 입력하면 반복문 종료
            break;
        }
    cout << "입력값: " << userInput << " 횟수 :"<< i << endl;
   }

    cout << "종료 되었습니다";
}