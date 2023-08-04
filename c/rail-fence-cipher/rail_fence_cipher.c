#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>

char * str_malloc(int len) {
   char * str = malloc(sizeof(char) * (len+1));

   for (int i = 0; i < len; i++) {
      *(str + i) = '?';
   }
   *(str + len) = '\0';
   return str;
}

char *encode(char *text, size_t rails) {
   char * encoded = str_malloc(strlen(text));

   char * head = encoded;

   for (size_t rail  = 0; rail < rails; rail++) {
      size_t curr_rail = 0;
      char dir = 0;
      for (char * ch = text; *ch; ch++){
         if (rail == curr_rail) {
            *encoded = *ch;
            encoded++;
         }
         if (curr_rail == 0) {
            dir = 1;
         }
         if (curr_rail == rails - 1) {
            dir = -1;
         }
         curr_rail += dir;
      }
   }

   return head;
}

char *decode(char *ciphertext, size_t rails)
{
   char * decoded = str_malloc(strlen(ciphertext));

   for (size_t rail  = 0; rail < rails; rail++) {
      size_t curr_rail = 0;
      char dir = 0;
      for (char * ch = decoded; *ch; ch++){
         if (rail == curr_rail) {
            *ch = *ciphertext;
            ciphertext++;
         }
         if (curr_rail == 0) {
            dir = 1;
         }
         if (curr_rail == rails - 1) {
            dir = -1;
         }
         curr_rail += dir;
      }
   }

   return decoded;
}
