// Write the function itob(n,s,b) that converts the
// integer n into a base b character representation in 
// the string s.  In particular, itob(n,s,16) formats n
// as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>

void itob(int,char[],int);
void reverse(char[]);
char findChar(int);

int main() {
  char s[100] = {};
  int a = -2147483648;
  //int a = 255;
  itob(a, s, 10);
  printf("%s\n", s);
  itob(a, s, 16);
  printf("%s\n", s);
  itob(a, s, 2);
  printf("%s\n", s);
}

void itob(int n,char s[], int b) {
  int i, sign, is_max;
  i = 0;
  sign = n;
  do {
    int x = n % b; 
    x = x >= 0 ? x : x * -1;
    s[i++] = findChar(x);
  } while ((n /= b) != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

char findChar(int n) {
  if (n < 0) {
    return -1; // todo: panic
  }

  if (n < 10) {
    return n + '0';
  }

  return n - 10 + 'A';
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
