#include <stdio.h>

#define LINEMAX 1000
#define TABCOUNT 8

int fetchline(char s[], int lim);

int main() {
	char line[LINEMAX], entabbed[LINEMAX];
	int len;
	while ((len = fetchline(line, LINEMAX)) > 0) {
		if (len == 1) continue;
		int tabcounter = 0;
		int tabIndex = 0;
		int space_count = 0;
		for (int i = 0; i <= len; i++) {
			char c = line[i];
			if (c == ' ') {
				++space_count;
				++tabcounter;
			} else {
				while (space_count > 0) {
					entabbed[tabIndex++] = ' ';
					space_count--;
				}
				entabbed[tabIndex++] = c;
				++tabcounter;
			}
			if (tabcounter == TABCOUNT) {
				tabcounter = 0;
				if (space_count > 0) {
					entabbed[tabIndex++] = '\t';
					space_count = 0;
				}
			}
		}
		printf("%s", entabbed);
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
