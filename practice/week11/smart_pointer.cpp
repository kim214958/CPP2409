#include <iostream>
#include <memory>
using namespace std;
int main(){
    unique_ptr<int[]> buf(new int[10]); // 스마트 포인터 배열 생성
    // 배열에 0~9를 담음
    for (int i = 0; i<10; i++) {
        buf[i] = i;
    }
    // 배열 내부 요소를 출력
    for (int i = 0; i<10; i++) {
        cout << buf[i] << " ";
    }
    cout << endl;
    return 0;
}
