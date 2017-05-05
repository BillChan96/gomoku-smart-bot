#include "Check.h"

double score(char** Table, int Size, int x, int y, char XO) {
	double Score = 0;
	char nXO = '\0';
	if (XO == 'X') nXO = 'O'; else nXO = 'X';
	//TH1: Highlest Move
	int MaxTemp = scorevip(Table, Size, x, y, XO, 0);
	if (MaxTemp != 0) { if (XO == 'X') { MaxTemp = -MaxTemp; } return MaxTemp; }
	//TH2: Another Move

	//B1: Vertical -----------------------------------------------
	int Count = 0, pos = x, Run = 0, up = 0, down = Size - 1;
	while (pos >= up) { //Go to Top (Max is 5 move)
		if (Table[pos][y] == XO) { Count++; Run++; }
		else if (Table[pos][y] == nXO || Run == 5) break;
		else if (Table[pos][y] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
		pos--;
	}
	pos = x;
	if (Run < 5) {
		while (pos < down) { //Go to Bottom (Max is 5 move)
			if (Table[pos + 1][y] == XO) { Count++; Run++; }
			else if (Table[pos + 1][y] == nXO || Run == 5) break;
			else if (Table[pos + 1][y] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
			pos++;
		}
	}
	//B2: Horizontal -----------------------------------------------
	Count = 0; pos = y; Run = 0; up = 0; down = Size - 1;
	while (pos >= up) { //Go to Top (Max is 5 move)
		if (Table[x][pos] == XO) { Count++; Run++; }
		else if (Table[x][pos] == nXO || Run == 5) break;
		else if (Table[x][pos] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
		pos--;
	}
	pos = y;
	if (Run < 5) {
		while (pos < down) { //Go to Bottom (Max is 5 move)
			if (Table[x][pos + 1] == XO) { Count++; Run++; }
			else if (Table[x][pos + 1] == nXO || Run == 5) break;
			else if (Table[x][pos + 1] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
			pos++;
		}
	}
	//B3: North East - Southwest && North west - south east
	//North East - Southwest---------------------------
	int pos1 = 0, pos2 = 0, up1 = 0, up2 = 0, down1 = 0, down2 = 0;
	Count = 0; Run = 0;
	if (x + y < Size) {
		//Left
		pos1 = x, pos2 = y, up1 = 0, up2 = x + y;
		while (pos1 >= up1 && pos2 <= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else if (Table[pos1][pos2] == nXO || Run == 5) break;
			else if (Table[pos1][pos2] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
			pos1--; pos2++;
		}
		pos1 = x, pos2 = y;
		if (Run < 5) {
			while (pos1 < up2 && pos2 > up1) {
				if (Table[pos1 + 1][pos2 + 1] == XO) { Count++; Run++; }
				else if (Table[pos1 + 1][pos2 + 1] == nXO || Run == 5) break;
				else if (Table[pos1 + 1][pos2 + 1] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
				pos1++; pos2--;
			}
		}
	}
	else {
		//Right
		pos1 = x, pos2 = y, up1 = x + y - Size + 1, up2 = Size - 1;
		while (pos1 >= up1 && pos2 <= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else if (Table[pos1][pos2] == nXO || Run == 5) break;
			else if (Table[pos1][pos2] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
			pos1--; pos2++;
		}
		pos1 = x, pos2 = y;
		if (Run < 5) {
			while (pos1 < up2 && pos2 > up1) {
				if (Table[pos1 + 1][pos2 + 1] == XO) { Count++; Run++; }
				else if (Table[pos1 + 1][pos2 + 1] == nXO || Run == 5) break;
				else if (Table[pos1 + 1][pos2 + 1] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
				pos1++; pos2--;
			}
		}
	}
	//North west - south east---------------------------
	Count = 0; Run = 0;
	if (x - y < 0) {
		//Right
		pos1 = x, pos2 = y, up1 = 0, up2 = abs(x - y), down1 = up1 + (Size - up2) - 1, down2 = up2 + (Size - up2) - 1;
		while (pos1 >= up1 && pos2 >= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else if (Table[pos1][pos2] == nXO || Run == 5) break;
			else if (Table[pos1][pos2] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
			pos1--; pos2--;
		}
		pos1 = x, pos2 = y;
		if (Run < 5) {
			while (pos1 < down1 && pos2 < down2) {
				if (Table[pos1 + 1][pos2 + 1] == XO) { Count++; Run++; }
				else if (Table[pos1 + 1][pos2 + 1] == nXO || Run == 5) break;
				else if (Table[pos1 + 1][pos2 + 1] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
				pos1++; pos2++;
			}
		}
	}
	else {
		//Left
		pos1 = x, pos2 = y, up1 = abs(x - y), up2 = 0, down1 = up1 + (Size - up1) - 1, down2 = up2 + (Size - up1) - 1;
		while (pos1 >= up1 && pos2 >= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else if (Table[pos1][pos2] == nXO || Run == 5) break;
			else if (Table[pos1][pos2] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
			pos1--; pos2--;
		}
		pos1 = x, pos2 = y;
		if (Run < 5) {
			while (pos1 < down1 && pos2 < down2) {
				if (Table[pos1 + 1][pos2 + 1] == XO) { Count++; Run++; }
				else if (Table[pos1 + 1][pos2 + 1] == nXO || Run == 5) break;
				else if (Table[pos1 + 1][pos2 + 1] == '\0') { Score += pow(1.0*Count, 2); Count = 0; Run++; }
				pos1++; pos2++;
			}
		}
	}
	if (XO == 'X') Score = -Score;
	return Score;
}

int scorevip(char** Table, int Size, int x, int y, char XO, int k) {
	int Smax = 0;
	int Count = 0, stop = 0, Run = 0, pos = x, up = 0, down = Size - 1;
	while (pos >= up) { //Go to Top (Max is 5 move)
		if (Table[pos][y] == XO) { Count++; Run++; }
		else { if (Table[pos][y] != '\0') { stop++; } break; };
		pos--;
	}
	pos = x;
	while (pos < down) { //Go to Bottom (Max is 5 move)
		if (Table[pos + 1][y] == XO) { Count++; }
		else { if (Table[pos + 1][y] != '\0') { stop++; } break; };
		pos++;
	}
	if (Count == 5) return 1000;
	else if (Count == 4) {
		if (stop == 0) return 900;
		else if (stop == 1 && XO == 'O') return 500;
	}
	else if (Count == 3 && stop == 0 && XO == 'O') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 800;
		}
		Smax += 100;
	}
	else if (Count == 2 && stop == 0 && XO == '0') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 700;
			else if (Temp == 900) return 600;
		}
	}
	//B2: Horizontal -----------------------------------------------
	Count = 0; stop = 0; Run = 0; pos = y; up = 0; down = Size - 1;
	while (pos >= up) { //Go to Top (Max is 5 move)
		if (Table[x][pos] == XO) { Count++; Run++; }
		else { if (Table[x][pos] != '\0') { stop++; } break; };
		pos--;
	}
	pos = y;
	while (pos < down) { //Go to Bottom (Max is 5 move)
		if (Table[x][pos + 1] == XO) { Count++; }
		else { if (Table[x][pos + 1] != '\0') { stop++; } break; };
		pos++;
	}
	if (Count == 5) return 1000;
	else if (Count == 4) {
		if (stop == 0) return 900;
		else if (stop == 1 && XO == 'O') return 500;
	}
	else if (Count == 3 && stop == 0 && XO == 'O') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 800;
		}
		Smax += 100;
	}
	else if (Count == 2 && stop == 0 && XO == '0') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 700;
			else if (Temp == 900) return 600;
		}
	}
	//B3: North East - Southwest && North west - south east
	//North East - Southwest---------------------------
	int pos1 = 0, pos2 = 0, up1 = 0, up2 = 0, down1 = 0, down2 = 0;
	Count = 0; stop = 0; Run = 0;
	if (x + y < Size) {
		//Phía Trên Trái
		pos1 = x, pos2 = y, up1 = 0, up2 = x + y;
		while (pos1 >= up1 && pos2 <= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else { if (Table[pos1][pos2] != '\0') { stop++; } break; };
			pos1--; pos2++;
		}
		pos1 = x, pos2 = y;
		while (pos1 < up2 && pos2 > up1) {
			if (Table[pos1 + 1][pos2 - 1] == XO) { Count++; }
			else { if (Table[pos1 + 1][pos2 - 1] != '\0') { stop++; } break; };
			pos1++; pos2--;
		}
	}
	else {
		//Right Bottom
		pos1 = x, pos2 = y, up1 = x + y - Size + 1, up2 = Size - 1;
		while (pos1 >= up1 && pos2 <= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else { if (Table[pos1][pos2] != '\0') { stop++; } break; };
			pos1--; pos2++;
		}
		pos1 = x, pos2 = y;
		while (pos1 < up2 && pos2 > up1) {
			if (Table[pos1 + 1][pos2 - 1] == XO) { Count++; }
			else { if (Table[pos1 + 1][pos2 - 1] != '\0') { stop++; } break; };
			pos1++; pos2--;
		}
	}
	if (Count == 5) return 1000;
	else if (Count == 4) {
		if (stop == 0) return 900;
		else if (stop == 1 && XO == 'O') return 500;
	}
	else if (Count == 3 && stop == 0 && XO == 'O') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 800;
		}
		Smax += 100;
	}
	else if (Count == 2 && stop == 0 && XO == '0') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 700;
			else if (Temp == 900) return 600;
		}
	}
	//North west - south east---------------------------
	Count = 0; stop = 0; Run = 0;
	if (x - y < 0) {
		//Right Top
		pos1 = x, pos2 = y, up1 = 0, up2 = abs(x - y), down1 = up1 + (Size - up2) - 1, down2 = up2 + (Size - up2) - 1;
		while (pos1 >= up1 && pos2 >= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else { if (Table[pos1][pos2] != '\0') { stop++; } break; };
			pos1--; pos2--;
		}
		pos1 = x, pos2 = y;
		while (pos1 < down1 && pos2 < down2) {
			if (Table[pos1 + 1][pos2 + 1] == XO) { Count++; }
			else { if (Table[pos1 + 1][pos2 + 1] != '\0') { stop++; } break; };
			pos1++; pos2++;
		}
	}
	else {
		//Left Bottom
		pos1 = x, pos2 = y, up1 = abs(x - y), up2 = 0, down1 = up1 + (Size - up1) - 1, down2 = up2 + (Size - up1) - 1;
		while (pos1 >= up1 && pos2 >= up2) {
			if (Table[pos1][pos2] == XO) { Count++; Run++; }
			else { if (Table[pos1][pos2] != '\0') { stop++; } break; };
			pos1--; pos2--;
		}
		pos1 = x, pos2 = y;
		while (pos1 < down1 && pos2 < down2) {
			if (Table[pos1 + 1][pos2 + 1] == XO) { Count++; }
			else { if (Table[pos1 + 1][pos2 + 1] != '\0') { stop++; } break; };
			pos1++; pos2++;
		}
	}
	if (Count == 5) return 1000;
	else if (Count == 4) {
		if (stop == 0) return 900;
		else if (stop == 1 && XO == 'O') return 500;
	}
	else if (Count == 3 && stop == 0 && XO == 'O') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 800;
		}
		Smax += 100;
	}
	else if (Count == 2 && stop == 0 && XO == '0') {
		if (k == 0) {
			int Temp = ScoreFuture(Table, Size, x, y, k);
			if (Temp == 1000) return 700;
			else if (Temp == 900) return 600;
		}
	}
	//exception
	return Smax;
}

bool isWin(char** Table, int Size, int x, int y, char XO) {
	int A = score(Table, Size, x, y, XO);
	if (A == 1000 || A == -1000)
		return true;
	return false;
}

bool isFull(char** Table, int Size) {
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (Table[i][j] == '\0')
				return false;
		}
	}
	return true;
}

int ScoreFuture(char** Table, int Size, int x, int y, int &k) {
	int SF = 100;
	k = 1;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (Table[i][j] == '\0') {
				Table[i][j] = 'O';
				int Temp = scorevip(Table, Size, x, y, 'O', k);
				if (Temp > SF) SF = Temp;
				Table[i][j] = '\0';
			}
		}
	}
	k = 0;
	return SF;
}