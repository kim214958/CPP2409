#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 2;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople <<"명의 회원 정보를 입력해주세요" << endl;
    
    // 사람의 이름, 나이 정보를 받고 그 정보를 이름배열, 나이배열에 추가 
    for (int i = 0; i<maxPeople; i++){
        cout << "사람 "<<i+1<<"의 이름: ";
        cin >> names[i];
        cout << "사람 "<<i+1<<"의 나이: ";
        cin >> ages[i];
    }

    // 검색에 사용할 특정나이 입력
    int ageThreshold;
    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
    cin >> ageThreshold;

    cout << ageThreshold << "세 이상인 고객들" << endl;
    int detectedPeople = 0;

    // 특정나이보다 큰 나이를 가진 배열 인덱스를 확인, 해당 사람의 이름, 나이를 표시
    for(int i =0; i<maxPeople; i++){
        if(ages[i]>= ageThreshold){
            cout << names[i] << " (" << ages[i] << "세)" << endl;
            detectedPeople++;
        }
    }
    // 특정나이보다 큰 나이를 가진 사람이 없으면 밑의 내용을 표시
    if (detectedPeople == 0){
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
    }
}