// Write the function strrindex(s,t) which returns the position of the
// rightmost occurence of t in s, or -1 if there is none.

#include <stdio.h>
#include <string.h>
int strrindex(char[], char[]);

int main() {
  char s[100] = "erry A very ";
  char t[10] = "erry";
  printf("%d\n", strrindex(s,t));
}

int strrindex(char s[], char t[]) {
  int i,j,k;
  for (i = strlen(s) - 1; i >= 0; i--) {
    for (j = i, k = strlen(t) -1; k > -1 && s[j] == t[k]; j--, k--)
      ;
    if (k < 0) 
      return i - strlen(t) + 1;
  }
  return -1;
}
