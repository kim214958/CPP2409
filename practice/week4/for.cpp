#include <iostream>
using namespace std;

int main(){
   long fact = 1;
   int n;
   cout<<"정수를 입력하시요 : ";
   cin >> n; // 사용자가 입력한 값

    // 1부터 사용자가 입력한 값 까지의 곱
   for(int i =1; i <=n; i++){
    fact = fact*i;
   }

   cout << n << "!은 " << fact << "입니다.\n";
    return 0;
}