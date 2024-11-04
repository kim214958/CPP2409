#include <iostream>
#include <string>
using namespace std;

class User{
	private:
		int hp;
	public:
		User();
		int GetHP();
		void DecreaseHP(int dec_hp);
		void IncreaseHP(int inc_hp);
};

