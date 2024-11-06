#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Movie 클래스
class Movie{
    public: // 접근제어자
    string MovieName; // 영화 제목
    float grade; // 영화 평점
    Movie() { MovieName =""; grade = 0; } // 기본 생성자
    Movie(string name, float a){ // 이름과 평점을 입력받는 생성자
        MovieName = name;
        grade = a;
    }
    void Print() { // 제목과 평점을 프린트하는 함수
        cout << "제목: " << MovieName << " 평점은: "<< grade << endl;
    }
};

int main(void){
    vector<Movie> objArray; // Movie 타입의 벡터 생성

    // 벡터에 Movie 객체를 생성, 추가
    objArray.push_back(Movie("titinic", 9.9));
    objArray.push_back(Movie("gone with the wind", 9.6));
    objArray.push_back(Movie("terminator", 9.9));

    for (Movie c : objArray) // objArray 벡터 내부의 Movie 타입의 객체에 대해서
        c.Print(); // Movie의 Print 함수 실행

    return 0;
}