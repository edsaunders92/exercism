#include "binary_search.h"
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
   int left = 0;
   int right = length - 1;
   while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == value) {
         return &arr[mid];
      }
      if (arr[mid] < value) {
         left = mid + 1;
      } else {
         right = mid - 1;
      }
   }
   return NULL;
}
