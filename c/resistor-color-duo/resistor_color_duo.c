#include "resistor_color_duo.h"

uint16_t color_code(enum resistor_band_t band[2]) {
   return band[0] * 10 + band[1];
}
