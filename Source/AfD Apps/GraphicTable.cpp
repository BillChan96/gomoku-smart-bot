#include "GraphicTable.h"

void PaintTable(int Size, int x, int y) {
	colorText(1);
	Size++;
	gotoxy(x, y);
	//Vẽ viền trên
	for (int i = 0; i < Size; i++) {
		if (i == 0) cout << "ÚÄ";
		else if (i == Size - 1) cout << "Ä¿";
		else cout << "ÄÂÄ";
	}
	//Xuất Viền Giữa
	for (int i = 0; i <= Size - 2; i++) {
		gotoxy(x, y + 2 * i + 1);
		for (int k1 = 0; k1 < Size; k1++) {
			if (k1 != Size - 1)
				cout << "³  ";
			else cout << "³";
		}
		//---------------------------
		if (i != Size - 2) {
			gotoxy(x, y + 2 * i + 2);
			for (int j = 0; j < Size; j++) {
				if (j == 0) cout << "ĂÄ";
				else if (j == Size - 1) cout << "Ä´";
				else cout << "ÄÅÄ";
			}
		}
		//---------------------------
	}
	//Vẽ Viền Dưới
	gotoxy(x, y + 2 * Size - 2);
	for (int i = 0; i < Size; i++) {
		if (i == 0) cout << "ÀÄ";
		else if (i == Size - 1) cout << "ÄÙ";
		else cout << "ÄÁÄ";
	}
}
void SupportTable(int x, int y) {
	int Max = 40, start = x;
	//Vẽ Khung - Dọc
	for (int k = 0; k < 2; k++) {
		if (k == 1)
			start += 64;
		for (int i = 0; i <= Max; i++) {
			gotoxy(start, y + i);
			cout << "³"; colorText(2); cout << "Û"; colorText(7); cout << "³";
		}
	}
	//Vẽ Khung Tỉ Số ----
	ScoreBoard(67, y, 0, 0);
	//Vẽ Khung Hiển Thị
	NoticeBoard(18, 28, 67, y + 5);
	//Vẽ Khung Điều Hướng
	NoticeBoard(15, 8, 67, y + 33);

	//------CÁC PHÍM CHỨC NĂNG--------
	colorText(14);
	gotoxy(72, y + 35);
	cout << "₫[f1]: Help";
	gotoxy(72, y + 38);
	cout << "₫[f2]: Replay";
	gotoxy(92, y + 35);
	cout << "₫[f3]: About";
	gotoxy(92, y + 38);
	cout << "₫[ESC]: Exit";
}
void rePaintTable(char** Table, int Size, int x, int y) {
	int sx = x + 1, sy = y + 1;
	PaintTable(Size, x, y);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (Table[i][j] == 'X') {
				retconsoleXY(x, y, i, j, sx, sy);
				gotoxy(sx, sy);
				colorText(12);
				cout << "X";
			}
			else if (Table[i][j] == 'O') {
				retconsoleXY(x, y, i, j, sx, sy);
				gotoxy(sx, sy);
				colorText(11);
				cout << "O";
			}
		}
	}
	gotoxy(sx, sy);
}