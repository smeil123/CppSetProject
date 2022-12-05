#include "GameSet.h" 

using namespace std;

GameSet::GameSet() {
	tot_cnt = 81;
	using_idx = 0;
	map_cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					Card temp = { i,j,k,l };
					deck.push_back(temp);
				}
			}
		}
	}

	SuffleDeck(); // 꼭 return을 받아야되나?

	//처음 12개 셋팅
	for (int i = 0; i < 12; i++) {
		card_map.push_back(deck[using_idx]);
		using_idx++;
		map_cnt++;
	}

}

void GameSet::SuffleDeck() {
	//unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	unsigned seed = 1; //테스트를 위해 임시 고정
	shuffle(deck.begin(), deck.end(),default_random_engine(seed));

}

void GameSet::PrintMap(int Start_x, int Start_y, int Width, int Height) {
	/**for (int i = 0; i < card_map.size(); i++) {
		cout << card_map[i].cnt << " " << card_map[i].color << " " << card_map[i].shaded << " " << card_map[i].shape << "\t///\t";

		if ((i+1) % 3 == 0) { cout << endl << endl << endl; }
	}**/

	m_DrawCard.GridDraw(Start_x, Start_y, Width, Height, card_map);
}

void GameSet::SpreadMap() {
	do {
		if (map_cnt < 12) { //현재 펼쳐진 카드가 12장 이하면, 빈자리에 채우기
			for (int i = 0; i < 12; i++) {
				if (card_map[i].cnt == -1) {
					card_map[i]=deck[using_idx];
					using_idx++;
					map_cnt++;
				}
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				card_map.push_back(deck[using_idx]);
				using_idx++;
				map_cnt++;
			}
		}
	} while (!CheckTotSet() && tot_cnt > using_idx);
}

bool GameSet::CheckTotSet() {
	bool check = false;

	for (int i = 0; i < map_cnt - 2; i++) {
		for (int j = i; j < map_cnt - 1; j++) {
			for (int k = j; k < map_cnt; k++) {
				if (CheckSet(i, j, k)) {
					check = true; //한 셋트라도 있으면 끗
					break;
				}
			}
		}
	}

	return check;
}

bool GameSet::CheckSet(int x, int y, int z) {
	bool check = true;

	if (!CheckSection(card_map[x].color, card_map[y].color, card_map[z].color)) { check = false; }
	else if (!CheckSection(card_map[x].cnt, card_map[y].cnt, card_map[z].cnt)) { check = false; }
	else if (!CheckSection(card_map[x].shape, card_map[y].shape, card_map[z].shape)) { check = false; }
	else if (!CheckSection(card_map[x].shaded, card_map[y].shaded, card_map[z].shaded)) { check = false; }

	return check;
}

bool GameSet::CheckSection(int s_x, int s_y, int s_z) {
	if (s_x == s_y &&  s_x == s_z) {
		return true;
	}
	else if (s_x != s_y && s_x != s_z && s_y != s_z) {
		return true;
	}
	else {
		return false;
	}
}

bool GameSet::ChoiceCard(int x, int y, int z) {
	//유효한 카드인지 체크
	if (card_map[x].cnt == -1 || card_map[y].cnt == -1 || card_map[z].cnt == -1) {
		cout << "잘못된 입력" << endl;

		return false;
	}

	if (CheckSet(x, y, z)) {
		cout << "정답" << endl;
		RemoveCard(x);
		RemoveCard(y);
		RemoveCard(z);

		SpreadMap(); // 12장으로 채우기

		return true;
	}
	else {
		cout << "오답" << endl;

		return false;
	}
}

void GameSet::RemoveCard(int x) {
	Card temp = { -1,-1,-1,-1 };
	card_map[x] = temp;
	map_cnt -= 1;
}

GameSet::~GameSet() {

}
