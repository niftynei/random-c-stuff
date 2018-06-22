#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int fetchline(char line[], int maxline);
void trimline(char line[], int len);

int main() {
	int len;
	char line[MAXLINE];
	while ((len = fetchline(line, MAXLINE)) > 0) {
		if (len == 1) continue; // skip blank lines
		trimline(line, len);
		printf("%s\n", line);
	}
	return 0;
}

int fetchline(char s[], int lim) {
	int c, i, prev;
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

void trimline(char line[], int len) {
	int i;
	for (i = len - 1; i > 0 && line[i] == '\0' || line[i] == '\t' || line[i] == ' ';i--) {
		line[i] = '\0';
	}
	printf("%d\n", i);
	// end the line early
}
