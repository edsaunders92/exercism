#include "binary.h"

int convert(const char *input) {
   int n = 0;

   for (; *input; input++) {
      n<<=1;
      if (*input == '1') {
         n+=1;
      } else if (*input != '0') {
         return INVALID;
      }
   }
   return n;
}
