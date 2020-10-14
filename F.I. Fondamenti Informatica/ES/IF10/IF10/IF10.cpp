// IF10.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
#define RIG 4
#define COL 3
using namespace std;

void lookForSella(int array[RIG][COL], int& rig, int& col, int& val) {

	for (int y = 0; y < rig; y++) {
		int minR = INT_MAX;
		int rx = 0, ry = 0;
		for (int x = 0; x < col; x++) {
			if (array[y][x] < minR) {
				rx = x; ry = y;
				minR = array[y][x];
			}
		}
		int maxC = INT_MIN;
		int cx = 0, cy = 0;
		for (int ty = 0; ty < rig; ty++) {
			if (array[ty][rx] > maxC) {
				maxC = array[ty][rx];
				cx = rx; cy = ty;
			}
		}
		if (rx == cx && ry == cy) {
			rig = ry;
			col = rx;
			val = array[ry][rx];
			return;
		}
	}
	rig = 0;
	col = 0;
	val = -1;
}
int main()
{
	//const int RIG = 4, COL = 3;
	int data[RIG][COL] {
		{33,7,71},
		{19,12,83},
		{29,4,15},
		{39,2,9}
	};
	int col = COL, rig = RIG, val = 0;

	lookForSella(data, rig, col, val);
	std::cout << "Trovato una sella a x:" <<col << " y:"<<rig<<" con il valore:"<<val;
}
