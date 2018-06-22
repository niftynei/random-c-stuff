#include <stdio.h>

int main() {
	int c, prev, saved;
	prev = '\0';
	saved = 0;
	while ((c = getchar()) != EOF) {
		if (prev == ' ' && c == ' ') {
			++saved;	
		} else {
			putchar(c);
		}
		prev = c;
	}
	printf("%d strokes saved\n", saved);
}
