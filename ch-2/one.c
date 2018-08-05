#include <stdio.h>

// Make a program to say how big a char, int and long are

// Let's compute it!

int main() {
	int theInt = 1;
	int u_i = 1;
	int counter = 1;

	while (u_i > 0) {
		u_i = u_i << 1;
		counter++;
		printf("int is %d at %d\n", u_i, counter);
	}

	printf("ended\n");
}
