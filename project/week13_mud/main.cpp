#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int map_x = 5; // 지도의 x크기
const int map_y = 5; // 지도의 y크기

// 플레이어의 좌표값들
int user_x = 0; // 가로 번호
int user_y = 0; // 세로 번호

// 사용자 정의 함수
bool checkXY(int x, int y);
void displayMap(vector<vector<int>> map);
bool checkGoal(vector<vector<int>> map, int x, int y);
bool nextpoint(int &x, int &y, int dx, int dy, vector<vector<int>> map, User *&current_player);
void checkEvent(vector<vector<int>> map, User *&user, int x, int y);
bool CheckUser(User *user);
// User를 상속한 마법사 클래스
class Magician : public User
{
public:
    Magician() : User()
    {
        hp = 10;
        item_cnt = 0;
    }

    int GetHP()
    {              // 캡슐의 getter
        return hp; // hp를 리턴
    };
    void DecreaseHP(int dec_hp)
    {                 // hp를 감소시키는 함수
        hp -= dec_hp; // 매개변수의 값만큼 hp를 감소시킨다.
    };
    void IncreaseHP(int inc_hp)
    {                 // hp를 증가시키는 함수
        hp += inc_hp; // 매개변수의 값만큼 hp를 증가시킨다.
    }
    void IncreaseCnt(int inc_cnt)
    {                        // itemCnt를 증가시키는 함수
        item_cnt += inc_cnt; // 매개변수의 값만큼 itemcnt를 증가시킨다.
    }
    // User의 DoAttack()을 오버라이딩
    void DoAttack() override
    {
        cout << "마법 사용" << endl;
    }
    friend ostream &operator<<(ostream &os, const Magician &player)
    {
        os << "현재 HP는 " << player.hp << "이고, "
           << "먹은 아이템은 총 " << player.item_cnt << "개 입니다.";
        return os;
    }
};

// User를 상속한 워리어 클래스
class Warrior : public User
{
public:
    Warrior() : User()
    {
        hp = 10;
        item_cnt = 0;
    }

    int GetHP()
    {              // 캡슐의 getter
        return hp; // hp를 리턴
    };
    void DecreaseHP(int dec_hp)
    {                 // hp를 감소시키는 함수
        hp -= dec_hp; // 매개변수의 값만큼 hp를 감소시킨다.
    };
    void IncreaseHP(int inc_hp)
    {                 // hp를 증가시키는 함수
        hp += inc_hp; // 매개변수의 값만큼 hp를 증가시킨다.
    }
    void IncreaseCnt(int inc_cnt)
    {                        // itemCnt를 증가시키는 함수
        item_cnt += inc_cnt; // 매개변수의 값만큼 itemcnt를 증가시킨다.
    }
    // User의 DoAttack()을 오버라이딩
    void DoAttack() override
    {
        cout << "베기 사용" << endl;
    }
    friend ostream &operator<<(ostream &os, const Warrior* &player)
    {
        os << "현재 HP는 " << player->hp << "이고, "
           << "먹은 아이템은 총 " << player->item_cnt << "개 입니다.";
        return os;
    }
    
};

// 메인  함수
int main()
{
    User *user; // 유저 생성
    string job; // 직업
    // 직업 선택
    while (true)
    {
        cout << "직업을 선택하세요: (magician, warrior)" << endl;
        cin >> job;
        if (job == "magician")
        {
            user = new Magician;
            break;
        }
        else if (job == "warrior")
        {
            user = new Warrior;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }
    }

    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    vector<vector<int>> map = {{0, 1, 2, 0, 4},
                               {1, 0, 0, 2, 0},
                               {0, 0, 0, 0, 0},
                               {0, 2, 3, 0, 0},
                               {3, 0, 0, 0, 2}};

    // 게임 시작
    while (1)
    { // 사용자에게 계속 입력받기 위해 무한 루프

        // 남은 체력을 표시해줌
        cout << "현재 HP: " << user->GetHP() << " "; // User.GetHP()의 반환값 cuttent_user.hp를 표시

        // 사용자의 입력을 저장할 변수
        string user_input = "";

        // 중복 이벤트 발생을 막기위한 변수
        bool correctmove = false;
        cout << "명령어를 입력하세요 (up,down,left,right,map,exit,info,attack): ";
        cin >> user_input;

        if (user_input == "up")
        {
            correctmove = nextpoint(user_x, user_y, 0, -1, map, user); // 이동하는 함수, 유효한 이동이면 true를 correctmove에 반환
            if (correctmove)
            {
                checkEvent(map, user, user_x, user_y); // 유효한 이동이면 event가 있는지 확인&발생
            }
        }
        else if (user_input == "down")
        {
            correctmove = nextpoint(user_x, user_y, 0, 1, map, user); // 위와 동
            if (correctmove)
            {
                checkEvent(map, user, user_x, user_y); // 유효한 이동이면 event가 있는지 확인&발생
            }
        }
        else if (user_input == "left")
        {
            correctmove = nextpoint(user_x, user_y, -1, 0, map, user); // 위와 동
            if (correctmove)
            {
                checkEvent(map, user, user_x, user_y); // 유효한 이동이면 event가 있는지 확인&발생
            }
        }
        else if (user_input == "right")
        {
            correctmove = nextpoint(user_x, user_y, 1, 0, map, user); // 위와 동
            if (correctmove)
            {
                checkEvent(map, user, user_x, user_y); // 유효한 이동이면 event가 있는지 확인&발생
            }
        }
        else if (user_input == "map")
        {
            // TODO: 지도 보여주기 함수 호출
            displayMap(map);
        }
        else if (user_input == "exit")
        {
            cout << "종료합니다."; // exit입력시 반복문 종료(프로그램 종료로 이어짐)
            break;
        }
        else if (user_input == "info")
        {
            cout << user << endl;
        }
        else if (user_input == "attack")
        {
            user->DoAttack();
        }
        // 위의 입력외 다른 입력시 다시 입력받음
        else
        {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (checkGoal(map, user_x, user_y))
        { // 목표 도달 여부 확인. 골을 달성하는 시점에는 턴이 넘어간 상태이다(행동 후 턴을 넘김) 그러므로 전 턴의 플레이어가 도착한 것이다.
            cout << user << "이(가) 목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        // 문제에서는 CheckUser는 hp가 0인지 확인하는 함수이지만, 종료조건을 CheckUser만 사용하면 로직에 오류가 생긴다.
        // 예를 들어 피가 1 남은 상태로 적을 만나면 피가 -2가 되므로 게임이 정상적으로 종료되지 않는다.
        // 이를 해결하기 위해서는 CheckUser의 조건을 0 이하로 수정하거나 아래의 조건처럼 수정해야한다.

        // 실패하는 시점에는 턴이 넘어간 상태이다(행동 후 턴을 넘김) 그러므로 전 턴의 플레이어가 실패한 것이다.
        if (user->GetHP() <= 0)
        { // CheckUser(user)가 false (user.hp == 0이면 false를 반환)이거나, user.GetHP()의 반환값 hp가 음수이면 if문을 실행
            cout << user << "의 HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            break;
        }
    }
    // 반복문이 종료되면 프로그램 종료
    delete user;
    return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map)
{
    for (int i = 0; i < map_y; i++)
    {
        for (int j = 0; j < map_y; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |"; // 양 옆 1칸 공백
            }

            else
            {
                int posState = map[i][j];
                switch (posState)
                {
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
bool checkXY(int x, int y)
{
    bool checkFlag = false;
    if (x >= 0 && x < map_x && y >= 0 && y < map_y)
    { // 유효한 좌표이면 true를 반환
        checkFlag = true;
    }
    return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int x, int y)
{
    // 목적지 도착하면
    if (map[y][x] == 4)
    {
        return true;
    }
    return false;
}

// 이동을 실행하는 함수, (dx,dy 는 추가로 이동하려는 거리)
bool nextpoint(int &x, int &y, int dx, int dy, vector<vector<int>> map, User *&current_player)
{
    // 이동하려는 좌표가 유효한 좌표이면 실행
    if (checkXY((x + dx), (y + dy)))
    {
        x = x + dx;      // 이동
        y = y + dy;      // 이동
        displayMap(map); // 이동 후 지도 표시
        cout << "이동했습니다." << endl;
        current_player->DecreaseHP(1); // 유효한 이동 후 체력을 1 감소, User 객체의 DecreaseHP(1)을 통해 객체의 hp 변수를 1 감소시킨다.
        return true;                   // 유효한 이동이면 true를 반환
    }
    // 이동하려는 좌표가 유효하지 않은 좌표이면 실행
    else
    {
        cout << "맵을 벗어났습니다. 다시 입력해주세요." << endl;
        return false; // 유효하지 않은 이동이면 false를 반환
    }
}

// 이벤트를 확인&처리하는 함수
void checkEvent(vector<vector<int>> map, User *&user, int x, int y)
{
    // 현재 자신의 위치에 이벤트가 있는지 확인
    int event = map[y][x];

    // 각 이벤트 처리 (1,2,3이 아니면 아무것도 처리하지 X)
    switch (event)
    {
    case 1:
        cout << "아이템이 있습니다." << endl;
        user->IncreaseCnt(1);
        break;
    case 2:
        cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
        user->DecreaseHP(2); // 적을 만나면 user 객체의 DecreaseHP(2)을 통해 객체의 hp 변수를 2 감소시킨다.
        break;
    case 3:
        cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
        user->IncreaseHP(2); // 포션을 만나면 user 객체의 IncreaseHP(2)을 통해  user 객체의 hp 변수를 2 증가시킨다.
        break;
    }
}
// User의 hp가 0인지 체크하는 함수
bool CheckUser(User *user)
{
    if (user->GetHP() <= 0) // 매개변수 객체의 GetHP를 통해 hp를 받아냄, 받은 값이 0이하면 false를 반환
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