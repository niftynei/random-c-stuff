#include <stdio.h>

int main() {
	int fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("F\tC\n");
	while (fahr <= upper) {
		printf("%d\t%d\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}

int celsius(int fahr) {
	return 5 * (fahr - 32) / 9;
}
