#include "hamming.h"

/**
 * @brier Calculates the Hamming Distance between two strings.
 *
 * The Hamming distance is only defined for sequences of equal length, so an attempt to calculate it between sequences of different lengths should not work.
 **/
int compute(const char *lhs, const char *rhs) {
   int dist = 0;
   for (;*lhs && *rhs; lhs++, rhs++) {
      if (*lhs != *rhs) {
         dist++;
      }
   }

   if (*lhs || *rhs) {
      return -1;
   }

   return dist;
}

