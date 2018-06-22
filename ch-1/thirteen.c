#include <stdio.h>

#define IN	1 /* inside a word */
#define OUT 	0 /* outside a word */
#define MAXWORD 50

int main() {
	int c, nl, nw, nc, state, index;
	state = OUT;
	nl = nw = nc = index = 0;

	int word[MAXWORD], count[MAXWORD];
	for (int i = 0; i < MAXWORD; i++) {
		count[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			word[index] = '\0';
			int len = 0;
			while (word[len] != '\0')
				len++;
			++count[len];
			index = 0;
			for (int i = 0; i < MAXWORD; i++) {
				word[i] = 0;
			}
		} else if (state == OUT) {
			state = IN;
			word[index++] = c;
			++nw;
		} else {
			word[index++] = c;
		}
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
		}
		printf("\n");
	}
	for (int i = 0; i < MAXWORD; i++) {
		if (count[i] == 0) continue;
		printf("%d", i);
	}
	printf("\n");
}
