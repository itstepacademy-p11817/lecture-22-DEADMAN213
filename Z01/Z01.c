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

void masSumComp(uint64_t* m, uint8_t size, uint64_t* sum, uint64_t* comp) {
	for (uint8_t i = 0; i < size; i++) {
		*sum += m[i];
		*comp *= m[i];
	}
}


int main(void) {
	uint64_t mas[100] = { 0 };
	uint8_t size = 0;

	uint64_t sum = 0;
	uint64_t comp = 1;

	printf("Input mas size: ");
	scanf_s("%hhi", &size);

	srand((unsigned int)time(NULL));
	initMas(mas, size);

	printf("Massive: ");
	printMas(mas, size);

	masSumComp(mas,size,&sum,&comp);
	printf("Sum of elements: %lli.\nComposition of elements: %lli.\n", sum, comp);

	return 0;
}