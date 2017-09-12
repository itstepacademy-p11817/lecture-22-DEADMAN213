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

uint64_t* searchMas(uint64_t* masA, uint64_t* masB, uint8_t sizeA, uint8_t sizeB) {
	for (uint8_t i = 0; i < sizeA - sizeB; i++) {
		
		if (masA[i] == masB[0]) {
			bool flag = true;
			for (uint8_t j = 0; j < sizeB; j++) {
				if (masA[i + j] != masB[j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				return masA + i;
			}
		}

	}

	return NULL;
}


int main(void) {
	uint64_t A[100] = { 0 };
	uint8_t sizeA = 0;

	uint64_t B[100] = { 0 };
	uint8_t sizeB = 0;

	printf("Input mas A size: ");
	scanf_s("%hhi", &sizeA);

	printf("Input mas B size: ");
	scanf_s("%hhi", &sizeB);


	srand((unsigned int)time(NULL));
	initMas(A, sizeA);

	printf("Mas A: ");
	printMas(A, sizeA);

	for (uint8_t i = 0; i < sizeB; i++) {
		printf("Input %hhi element: ", i);
		scanf_s("%lli", &B[i]);
	}

	printf("Mas B: ");
	printMas(B, sizeB);

	printf("Sub mas: ");
	uint64_t* pmas = searchMas(A, B, sizeA, sizeB);
	if (pmas) {
		for (uint8_t i = 0; i < sizeB; i++) {
			printf("%3lli", *(pmas + i));
		}
	}
	printf("\n");

	return 0;
}