#include "resistor_color.h"

int color_code(resistor_band_t resistor_band) {
   return resistor_band;
}

resistor_band_t * colors(void) {
   static resistor_band_t colors[10];
   for (resistor_band_t color = BLACK; color <= WHITE; color++) {
      colors[color] = color;
   }
   return colors;
}
