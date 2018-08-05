// Rewrite the functino lower, which converts upper case letters
// to lower case, witha  conditional expresion instead of if-else.
#include <stdio.h>

char lower(char c) {
	int distance = 'a' - 'A';
	return (c < 'a') ? c + distance : c;
}

int main() {
	printf("%c\n", lower('A'));
	printf("%c\n", lower('a'));
	printf("%c\n", lower('Z'));
	printf("%c\n", lower('z'));
}
