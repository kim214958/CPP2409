#include <iostream>
#include <string>
using namespace std;

//소문자로 변경하는 함수
string toLowerStr(string str){
    for(char &c : str){
        c = tolower(c);
    }
    return str;
}

//대문자로 변경하는 함수
string toUpperStr(string str){
    for(char &c : str){
        c = toupper(c);
    }
    return str;
}

//hammingdistance 확인 함수
int calHammingDist(string s1, string s2){
    //해밍거리 개수 확인
    int count = 0;

    //while반목문 안에 if조건으로 두 문자열이 다르면 다시 입력받음, 같으면 break
    while(true){
    if (s1.length()  != s2.length()){
            cout <<"오류: 길이가 다름"<< endl;
            cout << "DNA1: ";
            cin >> s1;
            cout << "DNA2: ";
            cin >> s2;
        }
    else
        break;
    }

    //입력받은 문자열의 소문자 문자열을 생성
    string a,b;
    a=toLowerStr(s1);
    b=toLowerStr(s2);

    //문자열의 해밍거리 확인
    for (int i = 0; i <a.length(); i++){
        if(a[i] !=b[i])
        count +=1;
    }
    return count;
}

// 문자열을 생성하여 해밍거리 계산 함수를 호출
int main(){
    string s1,s2;
    int count;
    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;
    count = calHammingDist(s1,s2);
    cout << "해밍 거리는 " << count << endl;
    return 0;
}