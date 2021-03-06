#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

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

uint8_t masSum(int64_t* masA, int64_t* masB, uint8_t sizeA, uint8_t sizeB, uint8_t pos) {
	for (uint8_t i = sizeA + sizeB - 1; i >= pos; i--) {
		masA[i] = masA[i - sizeB];
	}

	for (uint8_t i = 0; i < sizeB; i++) {
		masA[pos + i - 1] = masB[i];
	}

	return sizeA + sizeB;
}

int main(void) {
	uint64_t A[100] = { 0 };
	uint8_t sizeA = 0;

	uint64_t B[100] = { 0 };
	uint8_t sizeB = 0;

	printf("Input size A: ");
	scanf_s("%hhi", &sizeA);

	printf("Input size B: ");
	scanf_s("%hhi", &sizeB);

	srand((unsigned int)time(NULL));

	initMas(A, sizeA);
	printf("Mas A: ");
	printMas(A, sizeA);

	initMas(B, sizeB);
	printf("Mas B: ");
	printMas(B, sizeB);

	uint8_t pos = 0;
	printf("Input position: ");
	scanf_s("%hhi", &pos);
	sizeA = masSum(A, B, sizeA, sizeB, pos);
	printf("Mas A: ");
	printMas(A, sizeA);

	return 0;
}