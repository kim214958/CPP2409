#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    vector<int> v; // 벡터 생성
    for (int i = 0; i < 10; ++i) { // 0~9까지
        v.push_back(i); // 0~9의 값을 벡터 v에 차례대로 넣는다.
    }
    
    cout << "현재의 v = ";
    // 벡터에 들어있는 값들을 프린트
    for(auto&e:v)
        cout << e << " ";
    cout << endl;

    cout << "삭제 요소 = ";
    // 벡터가 공백이 될 때까지 pop_back() 호출
    while (v.empty() != true) {
        cout << v.back() << " ";
        v.pop_back();
    }  
    cout << endl; return 0;
}
