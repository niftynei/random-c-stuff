//
#include <stdio.h>
#include <string.h>

void itoa(int, char[], int);
void reverse(char[]);

int main() {
  char s[100] = {};
  int a = -2147483648;
  itoa(a, s, 20);
  printf("%s\n", s);
  itoa(255, s, 20);
  printf("%s\n", s);
  itoa(10348829, s, 20);
  printf("%s\n", s);
}

void itoa(int n, char s[], int min_width) {
  int i, sign;
  sign = n;
  i = 0;

  do {
    int x = n % 10; 
    x = x >= 0 ? x : x * -1;
    s[i++] = x % 10 + '0';
  } while ((n /= 10) != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  while (min_width > i) {
    s[i++] = ' ';
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
