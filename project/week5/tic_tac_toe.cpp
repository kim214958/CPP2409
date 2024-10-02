#include<iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{}; // 보드판 설정
    int x, y; // 사용자에게 입력받는 x,y좌표를 저장할 변수
    int countspace = 0; // 보드판의 채워진 칸을 확인하는 변수

    //보드판 초기화
    for(x=0; x<numCell; x++){
        for(y=0; y<numCell; y++){
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; //현재 유저의 돌을 저장하기 위한 문자 변수
    while(true){
        //1. 누구 차례인지 출력
        switch(k%2){
            case 0:
                cout <<"첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout <<"두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        // 2. 좌표 입력 받기 (직관성을 위해 x와 y를 따로따로 입력받게 만들었다.)
        cout <<"x 좌표를 입력하세요: "<< endl;;
        cin >> x ;
        cout <<"y 좌표를 입력하세요: "<< endl;;
        cin >> y ;
        

        // 3.입력받은 좌표의 유효성 체크
        if(x>= numCell || y>= numCell){
            cout << x << ", " << y << ": ";
            cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." <<endl;
            continue;
        }

        if (board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i <numCell; i++){
            cout << "---|---|---" << endl;
            for (int j =0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell-1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;
        countspace++;   // 표시된 공간을 카운트

        // 6-1. 빙고 시 승자 출력 후 종료 (가로)
        for(int k = 0; k <numCell; k++){
            for(int t = 0; t <numCell; t++){
                if(board[k][t] !=currentUser){
                    break;
                }
                if(t == numCell-1){
                    cout <<"가로 한 줄이 채워졌습니다."<< endl;
                    cout<<"승자는 "<<currentUser<<" 입니다." <<endl;
                    return 0;
                }
            }
        }
        // 6-2. 빙고 시 승자 출력 후 종료 (세로)
        for(int k = 0; k <numCell; k++){
            for(int t = 0; t <numCell; t++){
                if(board[t][k] !=currentUser){
                    break;
                }
                if(t == numCell-1){
                    cout <<"세로 한 줄이 채워졌습니다."<< endl;
                    cout<<"승자는 "<<currentUser<<" 입니다." <<endl;
                    return 0;
                }
            }
        }
        // 6-3. 빙고 시 승자 출력 후 종료 (대각선)
        for(int i =0; i<numCell; i++){
            if(board[i][i] != currentUser){
                break;
            }
            if(i == numCell-1){
                cout <<"대각선 한 줄이 채워졌습니다."<< endl;
                cout<<"승자는 "<<currentUser<<" 입니다." <<endl;
                return 0;
            }
        }

        // 7. 모든 칸이 다 차면 종료
        if(countspace == (numCell)*(numCell)){
            cout <<"모든 칸이 다 찼습니다."<<endl;
            return 0;
        }
        


    }
    return 0;
}