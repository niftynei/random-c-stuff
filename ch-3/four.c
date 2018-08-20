// In a two's complement number representation, our version of itoa does not 
// handle the largest negative number, that is, the value of n equal to
// -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
// regardless of what machine it runs on
//
#include <stdio.h>
#include <string.h>

void itoa(int, char[]);
void reverse(char[]);

int main() {
  char s[100] = {};
  int a = -2147483648;
  itoa(a, s);
  printf("%s\n", s);
}

void itoa(int n, char s[]) {
  int i, sign, is_max;
  i = is_max  = 0;

  if ((sign = n) < 0) {
    n = -n;
  }
  if (n < 0) { // max int won't flip, so take care of it
    n = (n + 1) * -1;
    is_max = 1;
  }
  do {
    if (i == 0 && is_max) {
      s[i++] = (n % 10 + 1) + '0';
    } else {
      s[i++] = n % 10 + '0';
    }
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
