#pragma once

#include "Card.h"
#include "DrawCard.h"

#include <iostream>
#include <stdio.h>

#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;


// 카드는 총8개 3가지 속성이 4세트 3^4
class GameSet {
private:
	int tot_cnt; // 총 카드 수
	int using_idx; // 사용한 카드 수
	int map_cnt; // 현재 펼쳐진 카드 수

	vector<Card> card_map; // 펼쳐진 카드
	vector<Card> deck; 

	DrawCard m_DrawCard; // 맵그리기

public:
	GameSet();
	void PrintMap(int Start_x, int Start_y, int Width, int Height);
	void SuffleDeck();
	void SpreadMap();
	bool CheckSet(int x, int y, int z);
	bool CheckTotSet();
	bool CheckSection(int s_x, int s_y, int s_z);
	bool ChoiceCard(int x, int y, int z);
	void RemoveCard(int x);
	~GameSet();

};