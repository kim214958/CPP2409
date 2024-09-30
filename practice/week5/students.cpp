#include <iostream>
using namespace std;

int main(){
    // 학생들의 수
    const int STUDENTS = 5;
    // 학생들의 수 만큼 성적 배열 생성
    int scores[STUDENTS];
    int sum = 0;
    int i, average;

    //성적 입력받음
    for(i=0; i<STUDENTS; i++){
        cout << "학생들의 성적을 입력하시오: ";
        cin >> scores[i];
    }
    //학생들의 수 만큼 성적합에 학생들의 성적을 더함
    for(i=0; i<STUDENTS; i++)
        sum += scores[i];
    
    //평균 = 성적의 합/학생의 수
    average = sum/ STUDENTS;
    cout << "성적 평균= " << average << endl;
    return 0;
}