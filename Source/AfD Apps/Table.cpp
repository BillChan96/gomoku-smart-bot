#include "Table.h"

char** newMemory(int Size) {
	char** A = new char*[Size];
	for (int i = 0; i < Size; i++) {
		A[i] = new char[Size];
	}
	return A;
}
bool restartTable(char** Table, int Size) {
	if (Table == NULL)
		return false;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			Table[i][j] = '\0';
		}
	}
	return true;
}
void controlTable(char** Table, int Size, int x, int y) {
	char X = 'X';
	int TDx = -1, TDy = -1, Sx = x + 1, Sy = y + 1;
	int S1 = 0, S2 = 0; //Score
	int StartBef = 0;
	//---------------------------------------
	int startleft = Sx, startup = Sy;
	int endright = Sx + Size * 3 - 3, enddown = Sy + Size * 2 - 2;
	Sx += 27; Sy += 18;
	gotoxy(Sx, Sy);
	while (true) {
		char c = _getch();
		//--physical keys
		colorText(10);
		if (c == 0x1B) {
			Exit(67, 8);
			break;
		}
		else if (c == 0x03B || c == 0x03C || c == 0x03D) {
			//F1
			if (c == 0x03B) {
				Help(67, 8);
				_getch();
				colorText(10);
				NoticeBoard(18, 28, 67, 8);
			}
			//F2
			else if (c == 0x03C) {
				restartTable(Table, Size);
				S1 = 0; S2 = 0;
				ScoreBoard(67, y, S1, S2);
			}
			//F3
			else if (c == 0x03D) {
				About(67, 8);
				_getch();
				colorText(10);
				NoticeBoard(18, 28, 67, 8);
			}
			colorText(8);
			rePaintTable(Table, Size, x, y);
		}
		//Check full table
		else if (isFull(Table, Size) == true) {
			restartTable(Table, Size);
			S1++; S2++; //Draw +1 point
			ScoreBoard(67, y, S1, S2);
			Dickens(67, 8);
			BeepLose();
			_getch();
			colorText(10);
			NoticeBoard(18, 28, 67, 8);
			rePaintTable(Table, Size, x, y);
		}
		//--Control keys 
		//----------------------------------------
		//Right
		else if (Sx < endright && c == 0x04D) {
			Sx += 3;
			gotoxy(Sx, Sy);
		}
		//Left
		else if (Sx > startleft && c == 0x04B) {
			Sx -= 3;
			gotoxy(Sx, Sy);
		}
		//Up
		else if (Sy > startup && c == 0x048) {
			Sy -= 2;
			gotoxy(Sx, Sy);
		}
		//Down
		else if (Sy < enddown && c == 0x050) {
			Sy += 2;
			gotoxy(Sx, Sy);
		}
		//Enter
		else if (c == 0x0D) {
			TDy = ((Sx - x) / 3);
			TDx = ((Sy - y) / 2);
			if (Table[TDx][TDy] == '\0') {
				colorText(12);
				cout << X;
				colorText(8);
				Table[TDx][TDy] = 'X';
				//cout << score(Table, Size, TDx, TDy, 'X');
				//check
				if (isWin(Table, Size, TDx, TDy, 'X') == true) {
					restartTable(Table, Size);
					S1 += 3; //Thắng + 3 điểm
					YouWin(67, 8);
					BeepWin();
					_getch();
					colorText(10);
					NoticeBoard(18, 28, 67, 8);
					ScoreBoard(67, y, S1, S2);
					rePaintTable(Table, Size, x, y);
					if (StartBef == 0) { //if this is X then next to O
						int A = Size / 2, B = Size / 2;
						Table[A][B] = 'O';
						retconsoleXY(x, y, A, B, Sx, Sy);
						gotoxy(Sx, Sy);
						colorText(11);
						cout << "O";
						StartBef = 1;
					}
					else StartBef = 0;
				}
				else {
					//Bot play
					int A = TDx, B = TDy;
					BestMove(Table, Size, A, B);
					Table[A][B] = 'O';
					retconsoleXY(x, y, A, B, Sx, Sy);
					gotoxy(Sx, Sy);
					colorText(11);
					cout << "O";
					colorText(8);
					//Check
					if (isWin(Table, Size, A, B, 'O') == true) {
						restartTable(Table, Size);
						S2 += 3;
						ScoreBoard(67, y, S1, S2);
						YouLose(67, 8);
						BeepLose();
						_getch();
						colorText(10);
						NoticeBoard(18, 28, 67, 8);
						rePaintTable(Table, Size, x, y);
						if (StartBef == 0) { //if this is O then next to X
							int A = Size / 2, B = Size / 2;
							Table[A][B] = 'O';
							retconsoleXY(x, y, A, B, Sx, Sy);
							gotoxy(Sx, Sy);
							colorText(11);
							cout << "O";
							StartBef = 1;
						}
						else StartBef = 0;
					}
				}
				int C, D;
				retconsoleXY(x, y, TDx, TDy, C, D);
				Sx = C; Sy = D;
				gotoxy(C, D);
			}
			else Beep(900, 100); //Warning if duplicate
		}
	}
}