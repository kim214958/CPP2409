#include <iostream>
using namespace std;

int main(){
    char secret_code = 'h';

    cout << "비밀코드를 맞춰보세요: ";
    char code;
    //코드를 입력받음
    cin >> code;

    //코드가 비밀코드보다 작으면 밑의 내용을 출력
    if(code < secret_code)
        cout << code << "뒤에 있음" << endl;

    //코드가 비밀코드보다 크면 밑의 내용을 출력
    else if (code > secret_code)
        cout << code << "앞에 있음" << endl;

    //코드와 비밀코드가 같으면 아래의 내용을 출력
    else
        cout << "맞추었습니다." << endl;

    return 0;
}