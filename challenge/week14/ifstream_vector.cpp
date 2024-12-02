#include <iostream>
#include <fstream> // 파일스트림을 위한 헤더
#include <vector>
using namespace std;

// 클래스 선언
class TempData
{
public:
    int hour;
    double temperature;
};

int main(){

    ifstream is("temp.txt");
    if (!is)
    {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    vector<TempData> temps; // 클래스 벡터 생성
    int hour;
    double temperature;

    while (is >> hour >> temperature)
    {
        temps.push_back(TempData{hour, temperature}); // txt 파일의 문자를 생성자의 매개변수로 생성
    }
    for (TempData t : temps){
        cout << t.hour << "시: 온도 " <<t.temperature << endl;
    }

    return 0;
}