#include "darts.h"
#include <math.h>

int score(struct coordinate_t landing_position) {
   float r = sqrt(pow(landing_position.x, 2) + pow(landing_position.y, 2)); 
   if (r > 10) {
      return 0;
   }
   if (r > 5) {
      return 1;
   }
   if (r > 1) {
      return 5;
   }
   return 10;
}
