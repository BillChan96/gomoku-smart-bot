#include <Windows.h>
#include <iostream>
using namespace std;

void gotoxy(int x, int y);
void colorText(int color);
void setBoardConsole(int width, int height, string title);
void playText(string Text, int Speed, int x, int y);
void retconsoleXY(int x, int y, int TDx, int TDy, int& sx, int& sy);
