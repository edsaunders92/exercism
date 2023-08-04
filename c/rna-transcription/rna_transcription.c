#include "rna_transcription.h"
#include <stdlib.h>

char *to_rna(const char *dna) {
   int len = 1;
   for (const char * ch = dna; *ch; ch++) {
      len+=1;
   }
   char * rna = malloc(sizeof(char) * len);
   char * head = rna;

   for (const char * ch = dna; *ch; ch++) {
      switch (*ch) {
         case 'G':
            *rna = 'C';
            break;
         case 'C':
            *rna = 'G';
            break;
         case 'T':
            *rna = 'A';
            break;
         case 'A':
            *rna = 'U';
            break;
      }
      rna++;
   }
   return head;
}
