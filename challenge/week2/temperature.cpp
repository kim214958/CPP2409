#include <iostream>
using namespace std;


int main(){
    float f;

    cout << "화씨온도 : " <<endl;
    cin >> f;
    cout << "화씨온도 : " << f << endl;
    cout << "섭씨온도 : " << (5.0/9.0)*(f-32) << endl;

}