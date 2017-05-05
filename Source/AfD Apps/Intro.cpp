#include "Intro.h"

void NoticeBoard(int width, int heigth, int x, int y) {
	for (int i = 0; i < heigth; i++) {
		gotoxy(x, y + i);
		if (i == 0) {
			for (int t = 0; t < width; t++) {
				if (t == 0) cout << "ÚÄ";
				else if (t == width - 1) cout << "Ä¿";
				else cout << "ÄÄÄ";
			}
		}
		else if (i == heigth - 1) {
			for (int b = 0; b < width; b++) {
				if (b == 0) cout << "ÀÄ";
				else if (b == width - 1) cout << "ÄÙ";
				else cout << "ÄÄÄ";
			}
		}
		else {
			for (int m = 0; m < width; m++) {
				if (m == 0) cout << "³ ";
				else if (m == width - 1) cout << " ³";
				else cout << "   ";
			}
		}
	}
}

void AfD(int x, int y) {
	x += 6; y += 7;
	colorText(12);
	gotoxy(x, y);
	printf("            =====\n");
	Sleep(100);
	gotoxy(x, y + 1);
	printf("          === ===\n");
	Sleep(100);
	gotoxy(x, y + 2);
	printf("        ===   ===\n");
	Sleep(100);
	gotoxy(x, y + 3);
	printf("      ===========\n");
	Sleep(100);
	gotoxy(x, y + 4);
	printf("    =============\n");
	Sleep(100);
	gotoxy(x, y + 5);
	printf("  ===         ===\n");
	Sleep(100);
	gotoxy(x, y + 6);
	printf("===           ===\n");
	Sleep(100);
	//---------------------------------
	colorText(10);
	gotoxy(x + 19, y);
	printf("   ======\n");
	Sleep(100);
	gotoxy(x + 19, y + 1);
	printf(" ===\n");
	Sleep(100);
	gotoxy(x + 19, y + 2);
	printf("===\n");
	Sleep(100);
	gotoxy(x + 19, y + 3);
	printf("=========\n");
	Sleep(100);
	gotoxy(x + 19, y + 4);
	printf("=========\n");
	Sleep(100);
	gotoxy(x + 19, y + 5);
	printf("===\n");
	Sleep(100);
	gotoxy(x + 19, y + 6);
	printf("===\n");
	Sleep(100);
	//----------------------------------
	colorText(11);
	gotoxy(x + 30, y);
	printf("======\n");
	Sleep(100);
	gotoxy(x + 30, y + 1);
	printf("===   =\n");
	Sleep(100);
	gotoxy(x + 30, y + 2);
	printf("===    =\n");
	Sleep(100);
	gotoxy(x + 30, y + 3);
	printf("===    =\n");
	Sleep(100);
	gotoxy(x + 30, y + 4);
	printf("===    =\n");
	Sleep(100);
	gotoxy(x + 30, y + 5);
	printf("===   =\n");
	Sleep(100);
	gotoxy(x + 30, y + 6);
	printf("======\n");
	Sleep(50);
	//-----SLOGAN--------------Apps Fun Daily
	colorText(14);
	playText("© AfD MEDIA PRODUCTION", 50, x + 15, y + 8);
	colorText(7);
}

void YouWin(int x, int y) {
	colorText(10);
	NoticeBoard(18, 28, x, y);
	gotoxy(x + 22, y + 15);
	colorText(12);
	cout << "YOU WIN";
	colorText(15);
	playText("PRESS ANY KEY TO CONTINUE", 30, x + 12, y + 17);
}

void YouLose(int x, int y) {
	colorText(10);
	NoticeBoard(18, 28, x, y);
	gotoxy(x + 21, y + 15);
	colorText(12);
	cout << "YOU LOSE";
	colorText(15);
	playText("PRESS ANY KEY TO CONTINUE", 30, x + 12, y + 17);
}

void Dickens(int x, int y) {
	colorText(10);
	NoticeBoard(18, 28, x, y);
	gotoxy(x + 21, y + 15);
	colorText(12);
	cout << "DICKENS";
	colorText(15);
	playText("PRESS ANY KEY TO CONTINUE", 30, x + 12, y + 17);
}

void ScoreBoard(int x, int y, int score1, int score2) {
	colorText(10);
	NoticeBoard(10, 5, x, y);
	//Thêm Chú Thích
	gotoxy(x + 4, y + 2);
	colorText(12);
	cout << "YOU";
	gotoxy(x + 20, y + 2);
	colorText(11);
	cout << "COM";
	//---------------
	colorText(15);
	gotoxy(x + 10, y + 2);
	cout << score1 << setw(6) << score2;
	colorText(10);
}

void About(int x, int y) {
	NoticeBoard(18, 28, x, y);
	x += 2; y += 4;
	colorText(11);
	gotoxy(x, y); cout << " _____   _____   _     _   _____   _   _.  _   _";
	gotoxy(x, y + 1); cout << "|_____| / ___ \\ | \\   / | / ___ \\ | | / | | \\ / |";
	gotoxy(x, y + 2); cout << "||      | | | | |  \\_/  | | | | | | |/ /  | | | |";
	colorText(12);
	gotoxy(x, y + 3); cout << "||  __  | | | | | |   | | | | | | | / /   | | | |";
	gotoxy(x, y + 4); cout << "|| |__| | | | | | |\\_/| | | | | | | . \\   | | | |";
	colorText(11);
	gotoxy(x, y + 5); cout << "||__||  | |_| | | |   | | | | | | | |\\ \\  | |_| |";
	gotoxy(x, y + 6); cout << "\\____/  \\_____/ |_|   |_| \\_____/ |_| \\_\\ \\_____/";
	colorText(14); playText("Console C/C++", 30, x + 35, y + 8);
	colorText(9); playText("þ", 30, x + 10, y + 15); colorText(15); playText("BillChan96", 50, x + 12, y + 15);
	colorText(9); playText("þ", 30, x + 10, y + 17); colorText(15); playText("Visual Studio 2013", 50, x + 12, y + 17);
	colorText(9); playText("þ", 30, x + 10, y + 19); colorText(15); playText("© 2015 AfD Media Production", 50, x + 12, y + 19);
	colorText(10);
}

void Help(int x, int y) {
	NoticeBoard(18, 28, x, y);
	x += 6; y += 2;
	char up = 30, down = 31, right = 16, left = 17;
	gotoxy(x, y);
	colorText(15);
	cout << "#Control:";
	colorText(15);
	NoticeBoard(3, 4, x + 16, y + 1);
	NoticeBoard(3, 4, x + 9, y + 5);
	NoticeBoard(3, 4, x + 16, y + 5);
	NoticeBoard(3, 4, x + 23, y + 5);
	colorText(13);
	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0: gotoxy(x + 19, y + 3);
			cout << up; break;
		case 1: gotoxy(x + 12, y + 6);
			cout << left; break;
		case 2: gotoxy(x + 19, y + 6);
			cout << down; break;
		case 3:  gotoxy(x + 26, y + 6);
			cout << right; break;
		}
	}
	gotoxy(x, y + 12);
	colorText(15);
	cout << "#You Win If:";
	gotoxy(x + 14, y + 14);
	colorText(15); cout << "______"; colorText(12); cout << "XXXXX"; colorText(15); cout << "_____";
	gotoxy(x + 14, y + 16);
	colorText(15); cout << "_____"; colorText(11); cout << "O"; colorText(12); cout << "XXXXX"; colorText(15); cout << "_____";
	gotoxy(x + 14, y + 18);
	colorText(15); cout << "_____"; colorText(11); cout << "O"; colorText(12); cout << "XXXXX"; colorText(11); cout << "O"; colorText(15); cout << "___";
	colorText(7);

	gotoxy(x, y + 20);
	colorText(15);
	cout << "#Score:";
	gotoxy(x + 14, y + 22);
	colorText(15); cout << "Win"; colorText(12); cout << "+3"; colorText(15); cout << "   Draw"; colorText(12); cout << "+1";
	colorText(10);
}

void Exit(int x, int y) {
	NoticeBoard(18, 28, x, y);
	gotoxy(x + 21, y + 15);
	colorText(12);
	cout << "GOOD BYE";
	colorText(15);
	playText("PRESS ANY KEY TO EXIT", 30, x + 15, y + 17);
}