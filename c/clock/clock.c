#include "clock.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

clock_t clock_create(int hour, int minute) {
   return clock_from_minutes(hour * 60 + minute);
}

clock_t clock_add(clock_t clock, int minute_add) {
   return clock_from_minutes(minutes_from_clock(clock) + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
   return clock_from_minutes(minutes_from_clock(clock) - minute_subtract);
}

clock_t clock_from_minutes(int minutes) {

   minutes %= 24 * 60;
   if (minutes < 0) {
      minutes += 24 * 60;
   }

   clock_t clock;

   int hour = minutes / 60;
   int minute = minutes % 60;

   sprintf(clock.text, "%02d:%02d", hour, minute);
   return clock;
}

int minutes_from_clock(clock_t clock) {
   char hourstr[3];
   hourstr[0] = clock.text[0];
   hourstr[1] = clock.text[1];
   hourstr[2] = '\0';
   int hour = atoi(hourstr);

   char minstr[3];
   minstr[0] = clock.text[3];
   minstr[1] = clock.text[4];
   minstr[2] = '\0';
   int minute = atoi(minstr);

   return hour * 60 + minute;
}

bool clock_is_equal(clock_t a, clock_t b) {
   return strcmp(a.text, b.text) == 0;
}
