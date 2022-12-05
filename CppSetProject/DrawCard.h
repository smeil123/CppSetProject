#pragma once

#include "Card.h"

#include <vector>

class DrawCard {
public:
	DrawCard();
	inline void gotoxy(int x, int y) {
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	void GridDraw(int Start_x, int Start_y, int Width, int Height, vector<Card> deck);
	void GridBox(int Start_x, int Start_y, int Width, int Height, Card c,int idx);
	/*void CardDraw(int Start_x, int Start_y, int Width, int Height);
	void TextDraw(string str, int x, int y);
	~DrawCard();*/
};