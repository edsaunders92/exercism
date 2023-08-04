#include "matching_brackets.h"

#include <string.h>

bool is_paired(const char *input) {
   int len = strlen(input);
   char stack[len];
   int index = 0;
   for (const char * ch = input; *ch; ch++) {
      char other = '\0';
      if (*ch == ']') {
         other = '[';
      }
      if (*ch == ')') {
         other = '(';
      }
      if (*ch == '}') {
         other = '{';
      }
      if (other && (index == 0 || stack[index - 1] != other)) {
         return false;
      } else if (other) {
         index--;
      }

      if (*ch == '[' || *ch == '(' || *ch == '{') {
         stack[index] = *ch;
         index++;
      }
   }
   return index == 0;
}
