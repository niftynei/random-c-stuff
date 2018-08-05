// Write the function htoi(s) which converts a string of hexadecimal
// digits (including an optional 0x or 0X) into its equivalent integer value.

#include <stdio.h>
#include <ctype.h>

int charValue(char i);
int htoi(char* input);

int main() {
	char *input = "0Xffff";
	printf("%d \n", htoi(input));
}

int htoi(char* input) {
	// todo: will bomb if passed empty string or 1-character string
	int start = 0;
	if (input[0] == '0' && tolower(input[1]) == 'x') {
		start = 2;
	}
	int result = 0;
	for (; input[start] != '\0'; start++) {
		int val = charValue(input[start]);
		if (val == -1) return -1;
		result = result * 16 + val; 	
	}
	return result;
}

int charValue(char i) {
	if (isdigit(i)) {
		return i - '0';
	}
	i = tolower(i);
	if (i < 'a' || i > 'f') {
		return -1;
	}
	return i - 'a' + 10;
}
