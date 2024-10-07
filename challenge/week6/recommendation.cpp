#include <iostream>
using namespace std;

// 3*3 userPreference 배열 생성
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreference [NUM_USERS][NUM_ITEMS];

// 사용자 마다 선호도를 받고 배열에 저장
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]){
    for(int i = 0; i< NUM_USERS; ++i){
        // preferences의 크기 만큼 사용자를 입력받음
        cout << "사용자" << (i+1) <<"의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";
        // preferences[NUM_USERS]의 크기 만큼 선호도를 입력받음
        for(int j =0; j< NUM_ITEMS; ++j){
            cin >> preferences[i][j];
        }
    }
}

// 사용자의 선호도를 비교, 가장 큰 값을 출력
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]){
    for(int i = 0; i< NUM_USERS; ++i){
        //맨 처음 비교할 배열의 요소
        int maxPreferenceIndex = 0;
        for(int j =1; j< NUM_ITEMS; ++j){
            /*비교하는 배열의 요소가 가장 큰 요소보다 크면,
            가장 큰 요소를 현재 비교하는 요소로 교체*/
            if(userPreference[i][j] > userPreference[i][maxPreferenceIndex]){
                maxPreferenceIndex = j;
            }
        }
        // 가장 큰 선호도의 배열 요소 출력
        cout << "사용자" << (i+1) <<"에게 추천하는 항목 : ";
        cout << (maxPreferenceIndex +1) << endl;
    }
}

int main(){
    // 두 함수를 userPreference를 인자로 호출
    initializePreferences(userPreference);
    findRecommendedItems(userPreference);
}