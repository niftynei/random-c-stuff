#include <stdio.h>
#define MAXLINE 1000

int fetchline(char line[], int max);
void reverse(char s[], int len);

int main() {
	int len;
	char line[MAXLINE];
	while ((len = fetchline(line, MAXLINE)) > 0) {
		if (len <= 1) continue; // skip blank lines
		reverse(line, len);
		printf("%s\n", line);
	}
	return 0;
}

// This truncates newlines
int fetchline(char s[], int lim) {
	int c, i, prev;
	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int len) {
	// do a swap!
	int end;
	end = len - 1;
	for (int i = 0; i < len/2; i++) {
		char tmp = s[i];
		s[i] = s[end];
		s[end] = tmp;
		end--;
	}
}
