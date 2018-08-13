// our binary search makes two tests inside the loop., when one would suffice
// (at the price of more tests outside). write a version with only one
// test inside the loop and measure the difference in run-time.

#include <stdio.h>
#include <time.h>

int binone(int x, int v[], int n);
int bintwo(int x, int v[], int n);

int main() {
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};

	clock_t start, t;
	double cpu_time_used;

	start = clock();
	int pos = binone(3,arr,10);
	t = clock();
	double time_taken = ((double) t) / CLOCKS_PER_SEC;
	printf("bin one %d in %f\n", pos, time_taken);

	start = clock();
	pos = bintwo(3,arr,10);
	t = clock();
	time_taken = ((double) t) / CLOCKS_PER_SEC;
	printf("bin two %d in %f\n", pos, time_taken);
}

int binone(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int bintwo(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	if (x == v[mid]) return mid;
	if (x == v[mid - 1]) return mid - 1;
	return -1;
}
