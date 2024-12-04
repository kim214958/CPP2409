#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> data = {5, 2, 4, 1, 3};
    sort(data.begin(), data.end()); // sorting
    for (int n : data) // 벡터의요소 출력
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}