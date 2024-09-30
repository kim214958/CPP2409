#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    //빈칸의 갯수를 새는 scount
    int scount;

    for(int i = 0; i <floor; i++){
        // 층마다 해당하는 빈칸을 생성하고, 빈칸의 갯수를 카운트
        for (int j = 0; j< floor-1-i; j++){
            cout<<"S";
            scount++;
        }
        // 피라미드는 총 층수 + (해당층수 -1)(== i) - 빈칸의 갯수만큼 *이 생성된다.
        for (int k = 0; k< floor+i-scount; k++){
            cout << "*";
            
        }
        scount = 0;
        cout <<endl;
    }
    return 0;
}