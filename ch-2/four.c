// Write an alternate version of squeeze(s1,s2) that deletes
// each characters in s1 that matches any character in string s2
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
	char hello[] = "my name is margot marvelous";
	squeeze(hello, "marck");
	printf("%s\n", hello);
}

// attempt one. let's be super fucking naive.
void squeeze(char s1[], char s2[]) {
	int i,j,k;
	for (i = j = 0; s1[i] != '\0'; i++) {
		int ok = 0;
		char c = s1[i];
		for (k = 0; s2[k] != '\0'; k++) {
			if (c == s2[k]) {
				ok = 1;
				break;
			}
		}	
		if (!ok) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0'; 
	// note that this leaves junk in s1 after the new \0
}
