#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
    int max;
    int min;
    int menu;
    bool condition = true;
    cout << maxPeople <<"명의 회원 정보를 입력해주세요" << endl;
    
    // 사람의 이름, 나이 정보를 받고 그 정보를 이름배열, 나이배열에 추가 
    for (int i = 0; i<maxPeople; i++){
        cout << "사람 "<<i+1<<"의 이름: ";
        cin >> names[i];
        cout << "사람 "<<i+1<<"의 나이: ";
        cin >> ages[i];
    }


    while(condition){
           // 메뉴 공지 및 선택
         cout <<"1. 가장 나이가 많은 사람"<< endl;
         cout <<"2. 가장 나이가 적은 사람"<< endl;
         cout <<"3. 종료"<< endl;
        
        cout << "메뉴를 입력하세요"<<endl;
        cin >> menu;
        switch(menu){
            case 1: {
            // 가장 큰 나이를 찾기
            max = ages[0];
            for(int i =0; i<maxPeople; i++){
             if(ages[i]>= max){
                max = ages[i];
                }
             }
             //가장 큰 나이를 가진 모든 사람들을 프린트
            for(int i =0; i<maxPeople; i++){
             if(ages[i]== max){
                cout << "가장 나이가 많은 사람: "<<names[i] << endl;
                }
             }
             break;}
            case 2: {
               // 가장 적은 나이를 찾기
            min = ages[0];
            for(int i =0; i<maxPeople; i++){
             if(ages[i]<= min){
                min = ages[i];
                }
             }
               // 가장 적은 나이를 가진 모든 사람들을 프린트
            for(int i =0; i<maxPeople; i++){
             if(ages[i]== min){
                cout << "가장 나이가 적은 사람: "<<names[i] << endl;
                }
             }
             break;}
             // 종료를 선택하면 while flag를 false로 변경
            case 3: cout << "종료" << endl;
               condition = false;
             break;
            default:
            // 잘못된 값을 입력하면 종료
             cout <<"잘못된 선택입니다."<< endl;
               condition = false;
             break;
        }
    }
}