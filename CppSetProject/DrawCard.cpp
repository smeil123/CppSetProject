#include "DrawCard.h"

DrawCard::DrawCard()
{

}

void DrawCard::GridDraw(int Start_x, int Start_y, int Width, int Height, vector<Card> deck) {
	int len = deck.size();
	int idx = 0;
	for (int i = 0; i < len/3; i++) {
		for (int j = 0; j < 3; j++) {
			//cout << j * (Width + 2) << "  " << i * (Height + 2) << endl;
			GridBox(Start_x+ j * (Width +4), Start_y+i * (Height + 1), Width, Height, deck[idx], idx);
			idx++;
		}
	}
	cout << endl;
	return;
}

void DrawCard::GridBox(int Start_x, int Start_y, int Width, int Height, Card c,int idx) {
	string Shapes[3][3] = { {"¡Þ","¢Â","¡ß"},{"¡à","¢Ã","¡á"},{"¡Û","¢Á","¡Ü" } };
	string Colors[3] = { "R","G","B" };

	for (int y = 0; y < Height; y++) {
		gotoxy(Start_x, Start_y + y);

		if (y == 0) {
			cout << "¦£";
			/*
			for (int x = 1; x < Width - 1; x++) {
				cout << "¦¡";
			}*/
			cout << idx << Colors[c.color];
			cout << "¦¤";
		}
		else if (y == Height - 1) {
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++) {
				cout << "¦¡";
			}
			cout << "¦¥";
		}
		else {
			cout << "¦¢";
			/*
			for (int x = 1; x < Width - 1; x++) {
				cout << "¡Û";
			}*/
			if (y <= c.cnt+1) {
				cout << Shapes[c.shape][c.shaded];
			}
			else {
				cout << "  ";
			}
			
			cout << "¦¢";
		}
	}
	return;
}