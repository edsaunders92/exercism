#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand) {
   int A = 0;
   int C = 0;
   int G = 0;
   int T = 0;

   char * output = malloc(sizeof(char) * 80);
   for (const char * nucleotide = dna_strand; *nucleotide; nucleotide++) {
      switch (*nucleotide) {
         case 'A':
            A++;
            break;
         case 'C':
            C++;
            break;
         case 'G':
            G++;
            break;
         case 'T':
            T++;
            break;
         default:
            output[79] = '\0';
            return output;
      }
   }


   sprintf(output, "A:%d C:%d G:%d T:%d", A, C, G, T);

   return output;
}
