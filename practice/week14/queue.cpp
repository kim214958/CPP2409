#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> qu;
    qu.push(100);
    qu.push(200);
    qu.push(300);
    while (!qu.empty()) // 큐에 요소가 남아있으면
    {   
        cout << qu.front() << endl; // 맨 앞에있는 요소 출력
        qu.pop(); // 큐 요소 하나 꺼냄
    }
    return 0;
}