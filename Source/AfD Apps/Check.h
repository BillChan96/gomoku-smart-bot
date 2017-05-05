#include <math.h>

double score(char** Table, int Size, int x, int y, char XO);
int scorevip(char** Table, int Size, int x, int y, char XO, int k);
bool isWin(char** Table, int Size, int x, int y, char XO);
bool isFull(char** Table, int Size);
int ScoreFuture(char** Table, int Size, int x, int y, int& k);