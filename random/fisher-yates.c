#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char jumble[] = {
	'a',
	'b',
	'c',
	'd',
	'e',
};

#define n_jumble (sizeof (jumble) / sizeof (char))

int pick(int);

int main() {
	// pre-seed the random number generator.
        srand(time(0));

	int i;
	for (i = 0; i < n_jumble; i++) {
		int r = pick(i);
		char save = jumble[i];
		jumble[i] = jumble[r];
		jumble[r] = save;
	}

	for (i = 0; i < n_jumble; i++) {
		printf("%c\n", jumble[i]);
	}

	return 0;
}

int pick(int max) {
	if (max == 0) return 0;
	while (1) {
		int r = rand();
		if (r < (RAND_MAX - (RAND_MAX % max))) {
			return r % max;
		}
	}
}
