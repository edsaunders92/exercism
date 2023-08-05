#include "secret_handshake.h"

#include <stdlib.h>

const char **commands(size_t number) {
   const char ** expected = malloc(sizeof(char * ) * 5);

   int index = 0;
   if ((number & 1) != 0) {
      expected[index++] = "wink";
   }
   if ((number & 2) != 0) {
      expected[index++] = "double blink";
   }
   if ((number & 4) != 0) {
      expected[index++] = "close your eyes";
   }
   if ((number & 8) != 0) {
      expected[index++] = "jump";
   }

   if ((number & 16) != 0) {
      for (int i = 0; i < index / 2; i++) {
         const char * temp = expected[i];
         expected[i] = expected[index - i - 1];
         expected[index - i - 1] = temp;
      }
   }

   return expected;
}


