#include "pangram.h"

bool is_pangram(const char *sentence) {
   if (!sentence) {
      return false;
   }
   char alphabet[26];

   for (int i = 0; i < 26; alphabet[i++] = 0);

   for (const char * chp = sentence; *chp; chp++) {
      char ch = *chp;
      if (ch > 'Z') {
         ch -= 'a';
      } else {
         ch -= 'A';
      }

      if (ch  >= 0 && ch < 26) {
         alphabet[(int) ch] = 1;
      }
   }

   int sum = 0;
   for (int i = 0; i < 26; sum += alphabet[i++]);

   return sum == 26;
}
