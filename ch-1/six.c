#include <stdio.h>

main() {
	int c;
	while (((c = getchar()) != EOF) != 0)
		putchar(c);
}
