#include "SearchMove.h"

double ScoreMax(char** Array, int Size) {
	double max = 0.0, temp;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (Array[i][j] == '\0') {
				Array[i][j] = 'O';
				temp = score(Array, Size, i, j, 'O');
				if (temp > max)
					max = temp;
				Array[i][j] = '\0';
			}
		}
	}
	return max;
}
double ScoreMin(char** Array, int Size) {
	double min = 0.0, temp;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (Array[i][j] == '\0') {
				Array[i][j] = 'X';
				temp = score(Array, Size, i, j, 'X');
				if (temp < min)
					min = temp;
				Array[i][j] = '\0';
			}
		}
	}
	return min;
}


int BestMove(char** Array, int Size, int& x, int& y) {
	double Max = ScoreMax(Array, Size);
	double Min = ScoreMin(Array, Size);
	int Exit = 0, SMax = 0;
	//cout << Min;
	//Not Dangerous -> Attack
	if (Max + Min >= 0 && Min < -1000 || Max == 1000) {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				if (Array[i][j] == '\0') {
					Array[i][j] = 'O';
					double TempScore = score(Array, Size, i, j, 'O');
					if (TempScore == 1000) {
						x = i; y = j;
						Array[i][j] = '\0';
						Exit = 1;
					}
					else if (TempScore == Max) {
						double Temp1, Temp2, Temp3, Temp = 0.0;
						Temp1 = Max + ScoreMax(Array, Size);
						Temp2 = Max - ScoreMin(Array, Size);
						//--------------------
						if (Temp1 >= Temp2) {
							Temp3 = ScoreMax(Array, Size);
							if (Temp3 > Temp1) Temp = Temp3;
							else Temp = Temp1;
						}
						else Temp = Temp2;
						//--------------------
						if (Temp > SMax) {
							SMax = Temp;
							x = i; y = j;
						}
					}
					Array[i][j] = '\0';
				}
			}
			if (Exit == 1) break;
		}
	}
	//Dangerous -> Defend
	else {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				if (Array[i][j] == '\0') {
					Array[i][j] = 'X';
					double TempScore = score(Array, Size, i, j, 'X');
					if (TempScore == -1000) {
						x = i; y = j;
						Array[i][j] = '\0';
						Exit = 1;
					}
					else if (TempScore == Min) {
						double Temp1, Temp2, Temp3, Temp = 0;
						Temp1 = ScoreMax(Array, Size) - Min;
						Temp2 = abs((int)Min) - ScoreMin(Array, Size);

						//--------------------
						if (Temp1 >= Temp2) {
							Temp3 = ScoreMin(Array, Size);
							if (Temp3 < Temp1) Temp = Temp3;
							else Temp = Temp1;
						}
						else Temp = Temp2;
						//--------------------
						if (Temp > SMax) {
							SMax = Temp;
							x = i; y = j;
						}
					}
					Array[i][j] = '\0';
				}
			}
			if (Exit == 1) break;
		}
	}
	return SMax;
}