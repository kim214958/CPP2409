#include <vector>
#include <iostream>
using namespace std;

int main(void){
    vector<int> objArray; // int 타입의 벡터 생성
    int grade; // 성적
    int sum = 0; // 성적의 합
    int students = 0; // 학생의 수
    int average = 0; // 평균
    while(1){ // 계속해서 성적을 입력받음

        // 성적을 입력받음
        cout << "성적을 입력하시오.(종료는 -1)"<<endl;
        cin >> grade;
        if(grade>=0){ // 성적이 양수이면
            objArray.push_back(grade); // objArray 벡터에 점수를 추가함
            ++students; // 학생의 수도 1 증가
        }
        else if((grade != -1) && (grade<0)){ // 성적이 -1이 아닌 음수이면
            cout << "양수인 점수를 입력해주세요"<<endl; // 음수임을 알리고 반복문을 continue
            continue;
        }
        else if(grade == -1){ // 입력받은 성적이 -1이면
            break; // 반복문 종료
        }
    }
    for (auto &e : objArray) { // objArray 벡터 내부의 값(int)에 대해서
        sum += e; // 벡터 내부의 값을 전부 더함
    }
    if(students !=0){ // 학생의 수가 0이 아니면(0으로 나누는 상황을 방지)
        average = sum/students; // 평균 = 점수의 총합 / 학생의 수
    }

    cout <<"성적 평균 = "<<average<<endl;

}