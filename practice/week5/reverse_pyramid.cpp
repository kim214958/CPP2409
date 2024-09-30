#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;

    for(int i = 0; i <floor; i++){
        //0층에는 0개, 1층에는 1개 ,,, floor-1층에는 floor-1개 빈칸이 생성된다.
        for (int j = 0; j< i; j++){
            cout<<"S";
        }
        //설정한 층의 역에 비례하여 *이 생성된다.
        for (int k = 0; k< 2*(floor-i-1)+1; k++){
            cout << "*";
        }
        cout <<endl;
    }
    return 0;
}