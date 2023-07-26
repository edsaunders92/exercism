#include "pascals_triangle.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows) {
   for (size_t row = 0; row < rows; row++) {
      free(triangle[row]);
   }
}

uint8_t **create_triangle(size_t rows) {
   uint8_t ** triangle = malloc(sizeof(uint8_t *) * rows);
   if (rows == 0) {
      triangle = malloc(sizeof(uint8_t*));
      triangle[0] = malloc(sizeof(uint8_t));
      triangle[0][0] = 0;
   }
   for (size_t row = 0; row < rows; row++) {
      triangle[row] = malloc(sizeof(uint8_t) * (rows));
      for (size_t col = 0; col < rows; col++) {
         size_t left = 0;
         size_t right = 0;

         if (col > 0 && row > 0) left = triangle[row-1][col-1];
         if (row > 0) right = triangle[row-1][col];

         triangle[row][col] = left + right;

         if (col == 0 && row == 0) triangle[row][col] = 1;
      }
   }
   return triangle;

}
