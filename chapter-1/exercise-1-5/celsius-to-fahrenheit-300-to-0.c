# include <stdio.h>

/*
print Celsius-Fahrenheit table
*/

int main() {
  int fahr;

  printf("Fahrenheit\tCelsius\n");

  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d\t\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

  return 0;
}