#include "SetConsole.h"

//Đưa Con Trỏ Tới Tọa Độ
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

//Đổi Màu Chữ
void colorText(int color) {
	HANDLE m_color;
	m_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(m_color, color);
}

//Cài đặt bảng console theo rộng + dài
void setBoardConsole(int width, int height, string title) {
	HANDLE wHnd;    // Handle để ghi lên console.
	HANDLE rHnd;    // Handle để đọc từ console.

	// Khởi tạo giá trị đọc/ghi cho handle.
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);

	// Thay đổi tiêu đề cho cửa sổ:
	SetConsoleTitle(TEXT(title.c_str()));

	// Thiết lập thông tin về kích thước mới:
	SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };

	// Thay đổi kích thước của Console:
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	// COORD chứa thông tin về kích thước bộ đệm:
	COORD bufferSize = { width, height };

	// Thay đổi kích thước bộ đệm:
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

//Chạy Chữ theo tọa độ và tốc độ
void playText(string Text, int Speed, int x, int y) {
	gotoxy(x, y);
	int Dem = 0, Go = 1;
	for (int i = 0; i < Text.length(); i++) {
		cout << Text[i];
		Dem++;
		if (Text[i] == '\n') {
			gotoxy(x, y + (Go++));
			Dem = 0;
		}
		Sleep(Speed);
	}
}

//lấy vị trí x,y trong mảng trên vị trí Table Game
void retconsoleXY(int x, int y, int TDx, int TDy, int& sx, int& sy) {
	//x,y: vị trí bản console
	//TDx,TDy là vị trí x,y trong mảng
	//sx,sy là vị trí x,y mảng trên bảng console
	sx = (TDy * 3) + x + 1;
	sy = (TDx * 2) + y + 1;
}

//Chuông Chiếng Thắng
void BeepWin() {
	for (int i = 0; i < 3; i++)
		Beep(700, 30);
	Sleep(70);
	Beep(900, 100);
}

//Chuông Thua Cuộc
void BeepLose() {
	for (int i = 0; i < 3; i++)
		Beep(700, 30);
	Sleep(70);
	Beep(400, 100);
}