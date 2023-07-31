#include "space_age.h"

#define EARTH_YEAR_IN_SECONDS = 31557600;

float earthYears(planet_t planet) {
   switch (planet) {
      case MERCURY: return 0.2408467;
      case VENUS: return 0.61519726;
      case EARTH: return 1.0;
      case MARS: return 1.8808158;
      case JUPITER: return 11.862615;
      case SATURN: return 29.447498;
      case URANUS: return 84.016846;
      case NEPTUNE: return 164.79132;
   }
}

float age(planet_t planet, int64_t seconds) {
   if (planet < MERCURY || planet > NEPTUNE) {
      return -1;
   }
   return (seconds / 31557600.0) / earthYears(planet);
}
