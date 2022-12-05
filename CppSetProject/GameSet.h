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


// ī��� ��8�� 3���� �Ӽ��� 4��Ʈ 3^4
class GameSet {
private:
	int tot_cnt; // �� ī�� ��
	int using_idx; // ����� ī�� ��
	int map_cnt; // ���� ������ ī�� ��

	vector<Card> card_map; // ������ ī��
	vector<Card> deck; 

	DrawCard m_DrawCard; // �ʱ׸���

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