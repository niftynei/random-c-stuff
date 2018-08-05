// write a function rightrot(x,n) that returns the value
// of the integer x rotated to the right by n bit positions.
#include <stdio.h>

void printbits(unsigned val) {
	int bit;
	int size = sizeof(unsigned short);
	unsigned int maxPow = 1<<(size*8-1);

	for (bit = 0; bit < size * 8; bit++) {
		printf("%i", !!(val & maxPow));
		val = val << 1;
	}
	printf("\n");
}

unsigned short rightrot(unsigned short x, int n) {
	int size = sizeof(unsigned short) * 8;
	unsigned mask = (x & ~(~0 << n)) << (size - n);
	return (x >> n) | mask;
}

int main() {
	unsigned x = 255;
	printf("start \t\t"); printbits(x);
	unsigned rot = rightrot(x, 8);
	printf("rot \t\t"); printbits(rot);
}
