// Write a function setbits(x,p,n,y) that returns x with the n
// bits that that begin at position p set to the rightmost n bits of y,
// leaving the other bits unchanged

#include <stdio.h>

unsigned int setbits(unsigned, int, int, unsigned);
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
	unsigned bits = setbits(255, 6, 4, 10);
	printbits(bits);
}

// set the n bits at p of x to the rightmost n-bits of y
unsigned int setbits(unsigned x, int p, int n, unsigned y) {
	unsigned newbits = getbits(y, n - 1, n); // rightmost n-bits of y
	// clear the n-bits of x at p
	unsigned cleared = (~0 << n) << (p - n) | ~(~0 << (p - n));
	return (x & cleared) | (newbits << (p - n));
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}
