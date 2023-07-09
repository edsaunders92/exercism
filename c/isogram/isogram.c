#include "isogram.h"

/**
 * @brief Determines if a word or phrase is an isogram.
 *
 * An isogram (also known as a "non-pattern word") is a word or phrase without a repeating letter, however spaces and hyphens are allowed to appear multiple times.
 *
 * Examples of isograms:
 *
 * lumberjacks
 * background
 * downstream
 * six-year-old
 *
 * The word *isograms*, however, is not an isogram, because the s repeats.
**/
bool is_isogram(const char phrase[]) {
   bool char_set[26] = { false };

   if (!phrase) {
      return false;
   }

   // Loop through char
   for (const char * ch = phrase; *ch; ch++) {
      int ord = *ch - 'a';
      // Make uppercase lowercase
      if (ord < 0) {
         ord -= 'A';
         ord += 'a';
      }

      if (ord >= 0 && ord < 26) {
         if (char_set[ord]) {
            return false;
         }
         char_set[ord] = true;
      }
   }

   return true;
}
