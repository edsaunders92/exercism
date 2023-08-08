#include "bob.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


bool is_question(char *greeting) {
   for(;*greeting && *(greeting+1);greeting++);
   return *greeting == '?';
}

bool is_lowercase(char ch) {
   return ch >= 'a' && ch <= 'z';
}

bool is_uppercase(char ch) {
   return ch >= 'A' && ch <= 'Z';
}

bool is_whitespace(char ch) {
   return ch == ' ' || ch  == '\t';
}

bool is_shouting(char* greeting) {
   for (char * ch = greeting; *ch; ch++) {
      if (is_lowercase(*ch)) {
         return false;
      }
   }
   for (char * ch = greeting; *ch; ch++) {
      if (is_uppercase(*ch)) {
         return true;
      }
   }
   return false;
}

bool is_silence(char * greeting) {
   return (greeting == NULL || !*greeting);
}

void rstrip(char * str) {
   char * end = str;
   for (;*end;end++);
   for (;str < end && is_whitespace(*(end-1));end--) {
      *(end-1) = '\0';
   }
}

char *hey_bob(char *greeting) {
   rstrip(greeting);
   if (is_silence(greeting)) {
      return "Fine. Be that way!";
   }

   if (is_shouting(greeting) && is_question(greeting)) {
      return "Calm down, I know what I'm doing!";
   }

   if (is_shouting(greeting)) {
      return "Whoa, chill out!";
   }
   
   if (is_question(greeting)) {
      return "Sure.";
   }

   return "Whatever.";
}

