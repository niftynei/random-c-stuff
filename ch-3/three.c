// write a function 'expand(s1,s2) that exands shorthand notations
// like a-z in the string s1 into the equivalent complete list abc...xyz 
// in s2. allow for letters of either case and digits, and be prepared to handle 
// cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing
// - is taken literally.
#include <stdio.h>

void expand(char[],char[]);

int main() {
	char s1[300] = "-a-";
	char s2[1000];
	expand(s1,s2);
	printf("%s\n", s2);
}

void expand(char s1[], char s2[]) {
	int i,j;
	char start, end, k;
	start = '0';
	end = 'z';
	
	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		char c = s1[i];
		if (c == '-') {
			if (i != 0) {
				start = s1[i - 1];
			} else {
				s2[j++] = start;
			}
			end = s1[i + 1] == '\0' ? 'z' : s1[i + 1];
			for (k = start + 1; k < end; k++) {
				s2[j++] = k;	
			}
			if (s1[i + 1] == '\0') {
				s2[j++] = end;
			}
		} else {
			s2[j++] = c;
			start = '0';
			end = 'z';
		}
	}

	s2[j] = '\0';
}
