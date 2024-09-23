#include <iostream>
using namespace std;

int main(){
   int choice;

    // 메뉴 공지 및 선택
   cout <<"1. 파일 저장"<< endl;
   cout <<"2. 저장 없이 닫기"<< endl;
   cout <<"3. 종료"<< endl;
   cin >> choice;


    // 선택에 따라 아래의 조건중 하나를 실행함. 1,2,3이 아닌 값을 입력하면 "잘못된 선택입니다"를 출력
   switch (choice){
    case 1:
        cout <<"파일 저장을 선택했습니다."<< endl;
        break;
    case 2:
        cout <<"파일 닫기를 선택했습니다."<< endl;
        break;
    case 3:
        cout <<"프로그램을 종료합니다."<< endl;
        break;
    default:
        cout <<"잘못된 선택입니다."<< endl;
        break;


   }
    return 0;
}