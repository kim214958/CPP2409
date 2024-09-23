#include <iostream>
using namespace std;

int main(){
    bool b;
    b=(1==2);   //1과 2가 같은가?
    cout << "1 == 2 = " << b <<endl;

    b = (1==1); //1과 1이 같은가?
    cout << "1 == 1 = " << b <<endl;

    return 0;
}