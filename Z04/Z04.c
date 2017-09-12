#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

uint8_t sum(uint8_t a, uint8_t b) {
	return a + b;
}

int8_t sub(uint8_t a, uint8_t b) {
	return a - b;
}

uint8_t com(uint8_t a, uint8_t b) {
	return a * b;
}

uint8_t div2(uint8_t a, uint8_t b) {
	return a / b;
}

int main(void) {
	uint8_t a = 0;
	uint8_t b = 0;
	uint8_t(*masOper[4])(uint8_t, uint8_t) = { sum, sub, com, div2 };

	printf("Input a: ");
	scanf_s("%hhi", &a);

	printf("Input b: ");
	scanf_s("%hhi", &b);

	uint8_t ind = 0;
	printf("Menu:\n");
	printf("1 - for sum.\n");
	printf("2 - for minus.\n");
	printf("3 - for composition.\n");
	printf("4 - for division.\n");
	printf("Input your choice: ");
	scanf_s("%hhi", &ind);

	printf("Result of operation: %hhi.\n", (*masOper[ind-1])(a, b));

	return 0;
}