#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void initMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		*(val + i) = rand() % 11;
	}
}

void printMas(int32_t* val, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		printf("%3i", *(val + i));
	}
	printf("\n");
}

uint32_t maxEl(uint32_t* mas, uint8_t size) {
	uint32_t max = *mas;
	for (uint8_t i = 1; i < size; i++) {
		if (mas[i] > max) {
			max = mas[i];
		}
	}

	return max;
}

uint32_t minEl(uint32_t* mas, uint8_t size) {
	uint32_t min = *mas;
	for (uint8_t i = 1; i < size; i++) {
		if (mas[i] < min) {
			min = mas[i];
		}
	}

	return min;
}

uint32_t avEl(uint32_t* mas, uint8_t size) {
	uint32_t max = maxEl(mas, size);
	uint32_t min = minEl(mas, size);
	uint32_t delta = abs((max + min) / 2 - *mas);
	uint32_t avr = *mas;
	
	for (uint8_t i = 1; i < size; i++) {
		if (abs((max + min) / 2 - *(mas + i)) < delta) {
			delta = abs((max + min) / 2 - *(mas + i));
			avr = *(mas + i);
		}
	}
	
	return avr;
}

uint32_t action(uint32_t* mas, uint8_t size, uint32_t (*pFun)(uint32_t*, uint8_t)) {
	return (*pFun)(mas, size);
}

int main(void) {
	uint32_t A[100] = { 0 };
	uint8_t sizeA = 0;
	uint32_t (*pMas[3])(uint32_t*, uint8_t) = { maxEl, minEl, avEl };

	printf("Input size A: ");
	scanf_s("%hhi", &sizeA);

	srand((unsigned int)time(NULL));

	initMas(A, sizeA);
	printf("Mas A: ");
	printMas(A, sizeA);

	uint8_t ch = 0;
	printf("Menu:\n");
	printf("1 - for max.\n");
	printf("2 - for min.\n");
	printf("3 - for average.\n");
	printf("Input your choice: ");
	scanf_s("%hhi", &ch);

	printf("Result of operation: %i.\n", action(A, sizeA, *pMas[ch - 1]));

	return 0;
}