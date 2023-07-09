#include "armstrong_numbers.h"
#include <math.h>

/**
 * @brief Determines if a number is an Armstrong number
 *
 * @link https://en.wikipedia.org/wiki/Narcissistic_number
 *
 * An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
 *
 * 9 is an Armstrong number, because `9 = 9^1 = 9`
 * 10 is *not* an Armstrong number, because `10 != 1^2 + 0^2 = 1`
 * 153 is an Armstrong number, because: `153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153`
 * 154 is *not* an Armstrong number, because: `154 != 1^3 + 5^3 + 4^3 = 1 + 125 + 64 = 190`
 */
bool is_armstrong_number(int candidate) {
   int sum = 0;
   int len = 0;

   for (int i = 1; i < candidate; i *= 10, len++);

   for (int i = candidate; i> 0; sum += pow(i%10,len), i /= 10);
   
   return sum == candidate;
}
