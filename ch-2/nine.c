// Use the observation that x &= x - 1 deletes the rightmost 
// 1-bit in x to write a faster version of bitcount

#include <stdio.h>

int bitcount(unsigned x) {
	int count = (x > 0) ? 1 : 0;
	while ((x &= (x - 1)) > 0) {
		count++;
	}
	return count;
}

int main() {
	int x = 11;
	printf("count of %d is %d\n", x, bitcount(x));
}
