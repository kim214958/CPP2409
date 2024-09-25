#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" <<endl;
    char ch; // 사용자 입력 저장하기 위한 변수

    while (cin >> ch) {
        ch = tolower(ch);  // 입력을 소문자로 변환 (대문자도 인식하기 위함)
        if (isalpha(ch)) { // 문자인지 아닌지 구분
            switch (ch) {// 모음 갯수 확인
                case 'a':
                    ++vowel;  
                    break;
                case 'e':
                    ++vowel; 
                    break;
                case 'i':
                    ++vowel; 
                    break;
                case 'o':
                    ++vowel;  
                    break;
                case 'u':
                    ++vowel; 
                    break;
                default:    // 자음 갯수 확인
                    ++consonant;  
                    break;
            }
        }
        else{ // 문자가 아니면 다시 입력하게 한다.
            cout << "잘못 입력했습니다." << endl;
            continue;
        }
    }
    cout << "모음 : " << vowel << endl;
    cout << "자음 : " << consonant << endl;
    return 0;
}