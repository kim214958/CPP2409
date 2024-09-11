#include <iostream>
using namespace std;


int main(){

    int money;
    int candy_price;

    cout << "돈을 입력하시오." << endl;
    cin >> money;
    cout << "캔디 가격을 입력하시오." << endl;
    cin >> candy_price;

    cout << "현재 가지고 있는 돈: " <<money << endl;
    cout << "캔디의 가격: " << candy_price << endl;
    cout << "최대로 살 수 있는 캔디 = " << money/candy_price <<endl;
    cout << "캔디 구입 수 남은 돈 = " << money%candy_price << endl;

}