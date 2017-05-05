#include "GraphicTable.h"
#include "SearchMove.h"
#include "Check.h"
#include "Intro.h"
#include <math.h>
#include <conio.h>

char** newMemory(int Size);
bool restartTable(char** Table, int Size);
void controlTable(char** Table, int Size, int x, int y);