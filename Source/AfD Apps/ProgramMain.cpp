#include "Table.h"

void main() {
	setBoardConsole(120, 48, "Loading...");
	setBoardConsole(120, 48, "AfD");
	AfD(30, 10);
	system("cls");
	setBoardConsole(120, 48, "GOMOKU AFD 1.0");
	SupportTable(0, 3);
	char** A = newMemory(20);
	restartTable(A, 20);
	rePaintTable(A, 20, 3, 3);
	controlTable(A, 20, 3, 3);
	delete[] A;
}