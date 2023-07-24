#include "pythagorean_triplet.h"

#include <stdlib.h>

void free_triplets(triplets_t * triplets) {
   free(triplets);
}

triplets_t * triplets_with_sum(int sum) {
   // Two loop
   int length = 0;
   for (int i = 1; i <= sum / 3; i++) {
      for (int j = i; j <= sum / 2; j++) {
         int k = sum - i - j;
         if (k < j) {
            continue;
         }
         if (i*i + j*j == k*k) {
            length += 1;
         }
      }
   }

   triplets_t * triplets = malloc(sizeof(triplets_t) + length * sizeof(triplet_t));
   triplets->count = length;

   int index = 0;

   for (int i = 1; i <= sum / 3; i++) {
      for (int j = i; j <= sum / 2; j++) {
         int k = sum - i - j;
         if (k < j) {
            continue;
         }
         if (i*i + j*j == k*k) {
            triplets->triplets[index].a = i;
            triplets->triplets[index].b = j;
            triplets->triplets[index].c = k;
            index += 1;
         }
      }
   }

   return triplets;
}

