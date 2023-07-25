#include "sieve.h"
#include "test-framework/unity.h"
#include <stdbool.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
   if (max_primes == 0) {
      return 0;
   }

   bool is_prime[limit+1];
   size_t n = 0;

   for (size_t i = 0; i <= limit; is_prime[i] = true, i++);

   is_prime[0] = false;
   is_prime[1] = false;

   for (size_t prime = 0; prime <= limit; prime++) {
      if (is_prime[prime]) {
         for (size_t i = 2 * prime; i < limit + 1; i += prime) {
            is_prime[i] = false;
         }
      }
   }

   for (size_t i = 0; i <= limit; i++) {
      if (is_prime[i]) {
         *(primes + n) = i;
         n += 1;
         if (n == max_primes) {
            break;
         }
      }
   }

   return n;
}

