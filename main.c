#include <stdio.h>
#include <math.h>

long int double_factorial(int n) //получаем целое число
{
   if (n == 0 || n == 1)
      return 1;
   return n * double_factorial(n - 2);
}

long double get_t(long double x)
{
   double numerator = 0, denominator = 0;
   for (int k = 0; k <= 10; k++)
   {
      numerator += pow( x, (2 * k + 1) ) / double_factorial(2 * k + 1);
      denominator += pow( x, (2 * k) ) / double_factorial(2 * k);
   }
   return numerator / denominator;
}

int main(void)
{
   long double input, result;
   scanf("%Lf", &input);
   result = ( 7 * get_t(0.25f) + 2 * get_t(1 + input) ) / ( 6 - get_t( input * input - 1 ) );
   printf("%20.15Lf", result);
}
