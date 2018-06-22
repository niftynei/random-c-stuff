#include <stdio.h>

#define LINEMAX 1000
#define TABCOUNT 10

int fetchline(char s[], int lim);

int main() {
	char line[LINEMAX], entabbed[LINEMAX];
	int len;
	while ((len = fetchline(line, LINEMAX)) > 0) {
		if (len == 1) continue;
		int tabcounter = 0;
		int tabIndex = 0;
		for (int i = 0; i <= len; i++) {
			char c = line[i];
			if (c == ' ') {
				int pointerAt = i + (TABCOUNT - tabcounter - 2);
				int isTabs = pointerAt < len;
				for (int p = pointerAt; p > i && p < len; p--) {
					if (line[p] != ' ') {
						isTabs = 0;
						break;
					}
				}
				if (isTabs) {
					entabbed[tabIndex++] = '\t';
					// advance i to the end of the tabstop
					i += TABCOUNT - tabcounter - 3;
					tabcounter = 0;
				} else {
					entabbed[tabIndex++] = c;
					++tabcounter;
				}
			} else {
				entabbed[tabIndex++] = c;
				++tabcounter;
			}
			if (tabcounter == TABCOUNT) {
				tabcounter = 0;
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
