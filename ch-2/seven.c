// Write a function invert(x,p,n) that returns x with the n bits
// that begin at position p inverted (ie 1 changed into 0 and vice versa),
// leaving the others unchanged.
#include <stdio.h>

unsigned invert(unsigned, int, int);
unsigned int getbits(unsigned, int, int);

void printbits(unsigned short val) {
	int bit;
	int size = sizeof(unsigned short);
	unsigned int maxPow = 1<<(size*8-1);

	for (bit = 0; bit < size * 8; bit++) {
		printf("%i", !!(val & maxPow));
		val = val << 1;
	}
	printf("\n");
}

int main() {
	printbits(255);
	unsigned x = invert(255,11,8);
	printbits(x);
}

unsigned invert(unsigned x, int p, int n) {
	unsigned flipfocus = (~getbits(x, p, n) & ~(~0 << n)) << (p - n + 1);
	unsigned cleared = (~0 << n) << (p - n + 1) | ~(~0 << (p - n + 1));
	return (x & cleared) | flipfocus;
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}
