#include "square_root.h"
#include <math.h>

/**
 * Return the sqaure root for a natural radicand
 *
 * Using the binary sqaure root estimate described here
 *
 * @link https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
 */
int square_root(int radicand) {
   float a = radicand;
   int n = 0;
   while (a >= 2) {
      a /= 4;
      n += 1;
   }
   return round((0.5 + 0.5 * a ) * pow(2,n));
}
