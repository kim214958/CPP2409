#include <iostream>
using namespace std;


// 게임을 진행하는 데 필요한 변수 선언
const int numCell = 3; // 보드판의 가로 세로 길이
int k = 0; // 누구 차례인지 체크하기 위한 변수
int numUser = 3; // 게임에 참가한 유저수
char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수


int isValid(int x, int y, int numCell){

  	if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때 -100을 반환
            return -100;
	}
	else if (board[x][y] != ' ') {// 좌표범위의 입력값이 중복될때 -200을 반환
			return -200;
	}
	else
		return 0; // 유효한 좌표면 0을 반환

}

//승자확인하는 함수 checkwin
bool checkWin(){
    
	//세로,가로 빙고를 확인하는 부분
	for (int i = 0; i < numCell; i++) {
		bool rowWin = true, columnWin = true; //가로빙고, 세로빙고 선언
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false; //만약 가로줄에 현재유저가 아닌 유저의 돌이 있으면 가로빙고=false
            if (board[j][i] != currentUser) columnWin = false; //만약 세로줄에 현재유저가 아닌 유저의 돌이 있으면 세로빙고=false
        }
		if(rowWin == true){
			cout << "가로에 모두 돌이 놓였습니다!" << endl;
			return true;	//가로 빙고이면 가로빙고임을 알리고 true를 반환
		}
		if(columnWin == true){
			cout << "세로에 모두 돌이 놓였습니다!" << endl;
			return true;	//세로 빙고이면 세로빙고임을 알리고 true를 반환
		}
	}	

	//(대각선 왼쪽 위 -> 오른쪽 아래) 빙고 확인
    for(int i =0; i<numCell; i++){
        if(board[i][i] != currentUser){ //대각선의 돌이 현재유저의 돌이 아니면 검증 종료(대각선 빙고X)
        	break;
        }
        if(i == numCell-1){ //모든 대각선을 확인했을 때
			cout << "왼쪽 위 -> 오른쪽 아래 대각선에 모두 돌이 놓였습니다!" << endl;
            return true;
        }
    }

    //(대각선 오른쪽 위 -> 왼쪽 아래) 빙고 확인
    for(int i = 0; i < numCell; i++) {
        if(board[i][numCell - 1 - i] != currentUser) { //대각선의 돌이 현재유저의 돌이 아니면 검증 종료(대각선 빙고X)
            break;
        }
        if(i == numCell - 1) { //모든 대각선을 확인했을 때
			cout << "오른쪽 위 -> 왼쪽 아래 대각선에 모두 돌이 놓였습니다!" << endl;
            return true;
        }
    }
	
	return false; // 승리조건을 만족하지 못하면 false를 return
}


int main() {

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임의 승자가 결정되기 전까지 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % numUser) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
        case 2: // 세번째 플레이어
            currentUser = 'H';
            break;
		}
		cout << k % numUser + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		/*if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
			cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
			continue;
		}*/
        if(isValid(x,y,numCell)==-100){
            cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
            continue;
        }
		if (isValid(x,y,numCell)==-200) {// 좌표범위의 입력값이 중복될때
			cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
			continue;
		}



		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
        //최대한 쪼개서 모양 구현
		for (int i = 0; i <numCell; i++){
            for(int i = 0; i<numCell-1; i++){
                cout << "---|";
                }
            cout << "---" << endl;
            for (int j =0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell-1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        for(int i = 0; i<numCell-1; i++){
                cout << "---|";
                }
            cout << "---" << endl;



		bool isWin = false; // 승리 여부
		
		isWin = checkWin();

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % numUser + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}