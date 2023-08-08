#include "roman_numerals.h"

#include <stdlib.h>

char *to_roman_numeral(unsigned int number) {
   char * roman = malloc(sizeof(char) * 20);
   char * start = roman;
   while (number >= 1000) {
      *roman = 'M';
      roman++;
      number -= 1000;
   }

   if (number >= 900) {
      *roman = 'C';
      roman++;
      *roman = 'M';
      roman++;
      number -= 900;
   }

   if (number >= 500) {
      *roman = 'D';
      roman++;
      number -= 500;
   }

   if (number >= 400) {
      *roman = 'C';
      roman++;
      *roman = 'D';
      roman++;
      number -= 400;
   }

   while (number >= 100) {
      *roman = 'C';
      roman++;
      number -= 100;
   }

   if (number >= 90) {
      *roman = 'X';
      roman++;
      *roman = 'C';
      roman++;
      number -= 90;
   }

   if (number >= 50) {
      *roman = 'L';
      roman++;
      number -= 50;
   }

   if (number >= 40) {
      *roman = 'X';
      roman++;
      *roman = 'L';
      roman++;
      number -= 40;
   }

   while (number >= 10) {
      *roman = 'X';
      roman++;
      number -= 10;
   }

   if (number >= 9) {
      *roman = 'I';
      roman++;
      *roman = 'X';
      roman++;
      number -= 9;
   }

   if (number >= 5) {
      *roman = 'V';
      roman++;
      number -= 5;
   }

   if (number >= 4) {
      *roman = 'I';
      roman++;
      *roman = 'V';
      roman++;
      number -= 4;
   }

   while (number >= 1) {
      *roman = 'I';
      roman++;
      number -= 1;
   }

   *roman = '\0';

   return start;
}
