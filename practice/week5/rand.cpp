#include <iostream>
using namespace std;

int main(){
    int list[10];
    int max;

    //무작위 int값을 크기가 10인 배열 list에 담는다.
    for(int i = 0; i<10; i++){
        int elem = rand() %100 +1;
        list[i] = elem;
        cout << elem << " ";
    }
    cout << endl;
    //첫번째 원소를 최대값이라 가정
    max = list[0];
    //만약 리스트에 있는 값이 max보다 크면 max값을 해당 값으로 변경한다.
    for (auto elem : list){
        if(elem > max)
            max = elem;

    }
    cout << "최대값="<< max << endl;
    return 0;
}