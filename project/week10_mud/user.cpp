#include "user.h"

		User::User(){
			hp = 20;
		};
		int User::GetHP(){
		return hp;
		};
		void User::DecreaseHP(int dec_hp){
			hp -= dec_hp;
		};
		void User::IncreaseHP(int inc_hp) {
			hp += inc_hp;
		}

