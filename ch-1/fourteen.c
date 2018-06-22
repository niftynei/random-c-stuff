#include <stdio.h>

#define MAXWORD 128

int main() {
	int count[MAXWORD], c;
	for (int i = 0; i < MAXWORD; i++) {
		count[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		count[c]++;
	}

	int max, x;
	max = x = 0;
	for (int i = 0; i < MAXWORD; i++) {
		if (count[i] > max) {
			max = count[i];
		}	
	}
	for (int level = max; level > 0; level--) {
		for (int i = 0; i < MAXWORD; i++) {
			if (count[i] == 0) continue;
			if (count[i] >= level) {
				printf("X");
			} else {
				printf(" ");
			}
			printf("\t");
		}
		printf("\n");
	}
	for (int i = 0; i < MAXWORD; i++) {
		if (count[i] == 0) continue;
		printf("%c\t", i);
	}
	printf("\n");
}
