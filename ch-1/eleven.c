#include <stdio.h>

#define IN	1 /* inside a word */
#define OUT 	0 /* outside a word */
#define MAXWORD 50

int main() {
	int c, nl, nw, nc, state, index;
	state = OUT;
	nl = nw = nc = index = 0;

	char word[MAXWORD];
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			word[index] = '\0';
			printf("%s\n", word);
			index = 0;
		} else if (state == OUT) {
			state = IN;
			word[index++] = c;
			++nw;
		} else {
			word[index++] = c;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
