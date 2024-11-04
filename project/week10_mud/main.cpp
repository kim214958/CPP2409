#include <iostream>
#include <string>
#include "user.h"
using namespace std;

User user; // User 객체 user 생성

const int mapX = 5; // 지도의 x크기
const int mapY = 5; // 지도의 y크기

// 유저의 위치를 저장할 변수
int user_x = 0; // 가로 번호
int user_y = 0; // 세로 번호

// 사용자 정의 함수
bool checkXY(int user_x,int user_y);
void displayMap(int map[][mapX]);
bool checkGoal(int map[][mapX]);
bool nextpoint(int dx, int dy, int map[][mapX]);
void checkEvent(int map[][mapX]);
bool CheckUser(User user);

// 메인  함수
int main() {

	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 중복 이벤트 발생을 막기위한 변수
		bool correctmove = false;
		cout << "명령어를 입력하세요 (up,down,left,right,map,exit): ";
		cin >> user_input;

		if (user_input == "up") {
            correctmove = nextpoint( 0, -1, map); //이동하는 함수, 유효한 이동이면 true를 correctmove에 반환
			if(correctmove)
				checkEvent(map); //유효한 이동이면 event가 있는지 확인&발생
        }
        else if (user_input == "down") {
            correctmove = nextpoint( 0, 1, map); // 위와 동
			if(correctmove)
				checkEvent(map); // 위와 동
        }
        else if (user_input == "left") {
            correctmove = nextpoint( -1, 0, map); // 위와 동
			if(correctmove)
				checkEvent(map); // 위와 동
        }
        else if (user_input == "right") {
            correctmove = nextpoint( 1, 0, map); // 위와 동
			if(correctmove)
				checkEvent(map); // 위와 동
        }
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map);
		}
		else if (user_input == "exit") {
			cout << "종료합니다."; //exit입력시 반복문 종료(프로그램 종료로 이어짐)
			break;
		}
		// 위의 입력외 다른 입력시 다시 입력받음
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}


		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 문제에서는 CheckUser는 hp가 0인지 확인하는 함수이지만, 종료조건을 CheckUser만 사용하면 로직에 오류가 생긴다.
		// 예를 들어 피가 1 남은 상태로 적을 만나면 피가 -2가 되므로 게임이 정상적으로 종료되지 않는다.
		// 이를 해결하기 위해서는 CheckUser의 조건을 0 이하로 수정하거나 아래의 조건처럼 수정해야한다.
		if(!CheckUser(user)||user.GetHP()<=0){ // CheckUser(user)가 false (user.hp == 0이면 false를 반환)이거나, user.GetHP()의 반환값 hp가 음수이면 if문을 실행
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			break;
		}
		//남은 체력을 표시해줌
		else
			cout<<"현재 HP: "<<user.GetHP()<<" "; // user.GetHP()의 반환값 user.hp를 표시

	}
	//반복문이 종료되면 프로그램 종료
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX]) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int user_y) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) { //유효한 좌표이면 true를 반환
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX]) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 이동을 실행하는 함수, (dx,dy 는 추가로 이동하려는 거리)
bool nextpoint(int dx, int dy, int map[][mapX]) {

	// 이동하려는 좌표가 유효한 좌표이면 실행
    if (checkXY((user_x + dx),(user_y + dy))) {
        user_x = user_x + dx; // 이동
        user_y = user_y + dy; // 이동
        displayMap(map); // 이동 후 지도 표시
        cout << "이동했습니다." << endl;
		user.DecreaseHP(1); // 유효한 이동 후 체력을 1 감소, user 객체의 DecreaseHP(1)을 통해 객체의 hp 변수를 1 감소시킨다.
		return true; // 유효한 이동이면 true를 반환
    }
	// 이동하려는 좌표가 유효하지 않은 좌표이면 실행 
	else {
        cout << "맵을 벗어났습니다. 다시 입력해주세요." << endl;
		return false; // 유효하지 않은 이동이면 false를 반환
    }

}

// 이벤트를 확인&처리하는 함수
void checkEvent(int map[][mapX]) {
	// 현재 자신의 위치에 이벤트가 있는지 확인
    int event = map[user_y][user_x];

	// 각 이벤트 처리 (1,2,3이 아니면 아무것도 처리하지 X)
	switch(event){
		case 1:
			cout<< "아이템이 있습니다."<<endl;
			break;
		case 2:
			cout<< "적이 있습니다. HP가 2 줄어듭니다."<<endl;
			user.DecreaseHP(2); // 적을 만나면 user 객체의 DecreaseHP(2)을 통해 객체의 hp 변수를 2 감소시킨다.
			break;
		case 3:
			cout<< "포션이 있습니다. HP가 2 늘어납니다."<<endl;
			user.IncreaseHP(2); // 포션을 만나면 user 객체의 IncreaseHP(2)을 통해  user 객체의 hp 변수를 2 증가시킨다.
			break;
	}
}
// User의 hp가 0인지 체크하는 함수
bool CheckUser(User user){
	if(user.GetHP()==0) // 매개변수 객체의 GetHP를 통해 hp를 받아냄, 받은 값이 0이면 false를 반환
		return false;
	else
		return true; // 반환받은 값이 0이 아니면 true를 반환
}

// 아래와 같이 작성해야 CheckUser 함수 하나만 호출해도 종료조건을 확인할 수 있다.
/*bool CheckUser(User user){
	if(user.GetHP()<=0)
		return false;
	else
		return true;
} */
