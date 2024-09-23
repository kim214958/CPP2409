#include <iostream>
using namespace std;

int main(){
   bool b;
   b = (1&&2);  //1 과 2 모두 참인가?
   cout << "1 && 2 = " << b << endl;

   b = (1&&0);  //1 과 0 모두 참인가?
   cout << "1 && 0 = " << b << endl;

   b = (0||0);  //0 또는 0이 참인가?
   cout << "0 || 0 = " << b << endl;

   b = (0||1);  //0 또는 1이 참인가?
   cout << "0 || 1 = " << b << endl;

   b = -1;      //-1이 참인가?
   cout << "b = " << b << endl;

    b = -1;     //-1이 아니면 참인가?
   cout << "!b = " << !b << endl;

    return 0;
}