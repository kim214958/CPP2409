#include <iostream>
using namespace std;

int main(){
    int choice;
    cout << "do-while문을 사용하여 메뉴 선택:" << endl;

    do{
        cout << "메뉴를 선택하세요 (1.옵션 1, 2.옵션 2, 3. 종료): ";
        cin >> choice;

         // 선택에 따라 아래의 조건중 하나를 실행함. 1,2,3이 아닌 값을 입력하면 "잘못된 선택입니다"를 출력
   switch (choice){
    case 1:
        cout <<"옵션 1 선택"<< endl;
        break;
    case 2:
        cout <<"옵션 2 선택"<< endl;
        break;
    case 3:
        cout <<"프로그램 종료."<< endl;
        break;
    default:
        cout <<"잘못된 선택"<< endl;
        break;
   }
    }while(choice !=3);//프로그램 종료를 선택할때 까지 반복

    return 0;
}