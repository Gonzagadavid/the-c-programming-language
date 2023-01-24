# include <stdio.h>

/*
print Fahrenheit-Celsius table
*/

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0; /* lower limit of temperature table */ 
  upper = 300; /* upper limit */
  step = 20; /* step size */

  fahr = lower;

  printf("Fahrenheit\tCelsius\n");

  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}