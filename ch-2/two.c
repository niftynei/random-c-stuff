// Write the loop equivalent to the `for` loop above, without using || or &&
//
// Loop from above:
//    for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; i++) {
// 	s[i] = c;
//    }

#include <stdio.h>

int main() {
	int i, lim;
	lim = 10;
	char c;
	for (i = 0;;i++) {
		if (i >= lim - 1) {
			break;
		}
		if ((c = getchar()) == '\n') {
			break;
		}	
		if (c == EOF) {
			break;
		}
		printf("i is %d; c is %c\n", i, c);
	}
}
