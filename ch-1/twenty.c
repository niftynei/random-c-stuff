#include <stdio.h>

#define LINEMAX 1000
#define TABCOUNT 10

int fetchline(char s[], int lim);

int main() {
	char line[LINEMAX], detabbed[LINEMAX];
	int len;
	while ((len = fetchline(line, LINEMAX)) > 0) {
		if (len == 1) continue;
		int tabcounter = 0;
		int detabIndex = 0;
		for (int i = 0; i <= len; i++) {
			char c = line[i];
			if (c == '\t') {
				while (TABCOUNT != tabcounter) {
					detabbed[detabIndex++] = ' ';
					tabcounter++;
				}
			} else {
				detabbed[detabIndex++] = c;
				tabcounter++;
			}
			if (tabcounter == TABCOUNT) {
				tabcounter = 0;
			}
		}
		printf("%s", detabbed);
	}
}

int fetchline(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
