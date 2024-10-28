#include <iostream>
#include <string>
using namespace std;
//숫자를 10으로 나눈 나머지를 각 자리수에 넣고, 10으로 나눈 몫은 다시 숫자에 넣는다.
bool checkNumber(int &number, int &first, int &second, int &third){
    first = number%10;
    number = number/10;

    second = number%10;
    number = number/10;

    third = number;
    //각 자리수가 전부 다르면 true를 반환
    if((first!=second) && (first!=third) && (second!=third)){
        return true;
    }
    else
        return false;
}


int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수 
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
        /*firstNum = randomNum%10;
        randomNum = randomNum/10;

        secondNum = randomNum%10;
        randomNum = randomNum/10;

        thirdNum = randomNum;

        if((firstNum!=secondNum) && (firstNum!=thirdNum) && (secondNum!=thirdNum)){
            same = true;
        }*/

       //유효한 숫자가 나올때 까지 반복
       same = checkNumber(randomNum,firstNum,secondNum,thirdNum);


		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
            /*guessFirst = userNumber%10;
            userNumber = userNumber/10;

            guessSecond = userNumber%10;
            userNumber = userNumber/10;

            guessThird = userNumber;

            if((guessFirst!=guessSecond) && (guessFirst!=guessThird) && (guessSecond!=guessThird)){
            same = true;
            }*/

            //3자리수가 아니면 다시 입력받음
			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

            //입력받은 숫자가 유효한지 확인
            same = checkNumber(userNumber,guessFirst,guessSecond,guessThird);

            //유효하지 않다면 중복된 숫자가 있음을 알리고 다시 while문으로 반복
            if (same ==false){
                cout<<"입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요"<<endl;
            }
            //유효한 숫자를 입력하면 반복문을 종료
			if (same == true) {
				break;
			}
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성

        //각 자리수가 내가 생각한 숫자랑 일치하면 strike를 1 올림
        if(firstNum == guessFirst){++strike;}
        if(secondNum == guessSecond){++strike;}
        if(thirdNum == guessThird){++strike;}

        //strike가 아니고 다른자리수의 숫자와 같다면 ball을 1 올림
        if( (firstNum==guessSecond) && (firstNum != guessFirst)){++ball;}
        if( (firstNum==guessThird) &&(firstNum != guessFirst)){++ball;}
        if((secondNum==guessFirst) && (secondNum != guessSecond) ){++ball;}
        if((secondNum==guessThird) && (secondNum != guessSecond) ){++ball;}
        if((thirdNum==guessFirst) &&(thirdNum != guessThird)){++ball;}
        if((thirdNum==guessSecond) && (thirdNum != guessThird) ){++ball;}
        
		

		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}