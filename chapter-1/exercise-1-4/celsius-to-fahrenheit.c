# include <stdio.h>

/*
print Celsius-Fahrenheit table
*/

void main() {
  int celsius, fahr;
  int lower, upper, step;

  lower = 0; /* lower limit of temperature table */ 
  upper = 300; /* upper limit */
  step = 20; /* step size */

  celsius = lower;

  printf("Celsius\tFahrenheit\n");

  while (celsius <= upper) {
    fahr = celsius * 9 / 5 + 32;
    printf("%d\t\t%d\n", celsius, fahr);
    celsius = celsius + step;
  }
}