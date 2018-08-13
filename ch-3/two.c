// Write a function escape(s,t) that converts characters like
// newline and tab into visible escape sequences like \n and \t
// as it copies the string t into s. Use a switch. write a function
// for the other direction as well, converting escape sequences into
// the real characters.
#include <stdio.h>

void escape(char[], char[]);
void unescape(char[], char[]);

int main() {
	char t[26] = "hello\tthere\n'end";
	char s[26], x[26];
	escape(t,s);
	printf("from %s to\n%s\n", t,s);
	unescape(s,x);
	printf("from %s to\n%s\n", s,x);
}

void unescape(char t[], char s[]) {
	int i, j;
	char next;
	j = 0;
	for (i = 0; t[i] != '\0'; i++) {
		char c = t[i];
		switch (c) {
			case '\\':
				next = t[i+1];
				switch (next) {
					case 't':
						s[j++] = '\t';
						i++;
						break;
					case 'n':
						s[j++] = '\n';
						i++;
						break;
					default:
						s[j++] = c;
						break;
				}
				break;
			default:
				s[j++] = c;
				break;
		}
	}
	s[j] = '\0';
}

void escape(char t[], char s[]) {
	int i, j;
	j = 0;
	for (i = 0; t[i] != '\0'; i++) {
		char c = t[i];
		switch (c) {
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = c;
				break;
		}
	}
	s[j] = '\0';
}
