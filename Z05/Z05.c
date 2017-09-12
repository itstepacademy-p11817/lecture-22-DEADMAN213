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

void masSum(int64_t* masA, int64_t* masB, int64_t* masC, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		masC[i] = masA[i] + masB[i];
	}
}

int main(void) {
	uint64_t A[100] = { 0 };
	uint64_t B[100] = { 0 };
	uint64_t C[100] = { 0 };
	uint8_t size = 0;

	printf("Input size of massives: ");
	scanf_s("%hhi", &size);

	srand((unsigned int)time(NULL));
	
	initMas(A, size);
	printf("Mas A: ");
	printMas(A, size);

	initMas(B, size);
	printf("Mas B: ");
	printMas(B, size);

	masSum(A, B, C, size);
	printf("Mas C: ");
	printMas(C, size);

	return 0;
}