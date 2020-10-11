#include "pch.h"
#include <iostream>

char* leggiVettore() {


}
void stampaVettore(int *testArray) {
	for (size_t x = 0; x < sizeof(*testArray) / sizeof(**testArray); ++x) {
		for (int y = 0; y < sizeof(testArray) / sizeof(*testArray); ++y) {
			if (testArray[x][y].foo == false) {

			}
		}
	}

}
int main()
{

	std::cout << "Hello World!\n";
}
