// extend atof to handle scientific notation of the form
//   123.45e-6
// where a floating point number may be followed by e or E
// and an optionally signed exponent.
#include <stdio.h>
#include <ctype.h>

int main() {
  double atof(char []);
  //char line[100] = "-192.01001";
  char line[100] = "-2.10E-6";
  printf("%f\n", atof(line));
}

double atof(char s[]) {
  double val, power;
  int i, sign, e_sign, e_pow;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  e_pow = 0;
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    e_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
      i++;
    for (e_pow = 0; isdigit(s[i]); i++) {
      e_pow = 10 * e_pow + (s[i] - '0');
    } 
  }

  val = sign * val / power;
  if (!e_pow) return val;
  if (e_sign > 0) {
    for (i = 0; i < e_pow; i++) {
      val *= 10.0;
    }
  } else {
    for (i = 0; i < e_pow; i++) {
      val /= 10.0;
    }
  }
  return val;
}
