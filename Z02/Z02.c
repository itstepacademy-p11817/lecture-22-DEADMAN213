#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

void initMas(int64_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		*(val + i) = rand() % 11;
	}
}

void printMas(int64_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		printf("%3lli", *(val + i));
	}
	printf("\n");
}

void masNegPosZer(uint64_t* m, uint8_t size, uint64_t* neg, uint64_t* pos, uint64_t* zer) {
	for (uint8_t i = 0; i < size; i++) {
		if (m[i] < 0) {
			(*neg)++;
		}

		if (m[i] > 0) {
			(*pos)++;
		}

		if (m[i] == 0) {
			(*zer)++;
		}
	}
}


int main(void) {
	uint64_t mas[100] = { 0 };
	uint8_t size = 0;

	uint64_t neg = 0;
	uint64_t pos = 0;
	uint64_t zer = 0;

	printf("Input mas size: ");
	scanf_s("%hhi", &size);

	srand((unsigned int)time(NULL));
	initMas(mas, size);

	printf("Massive: ");
	printMas(mas, size);

	masNegPosZer(mas, size, &neg, &pos, &zer);
	printf("Negative elements: %lli.\nPositive elements: %lli.\nZeros: %lli.\n", neg, pos, zer);

	return 0;
}