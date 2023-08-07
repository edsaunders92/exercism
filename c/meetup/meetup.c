#include "meetup.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

enum DaysOfWeek {
   Saturday = 0,
   Sunday,
   Monday,
   Tuesday,
   Wednesday,
   Thursday, 
   Friday, 
};

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week) {
   int day, start, dir = 1;

   if (strcmp(day_of_week, "Sunday") == 0) {
      day = Sunday;
   } else if (strcmp(day_of_week, "Monday") == 0) {
      day = Monday;
   } else if (strcmp(day_of_week, "Tuesday") == 0) {
      day = Tuesday;
   } else if (strcmp(day_of_week, "Wednesday") == 0) {
      day = Wednesday;
   } else if (strcmp(day_of_week, "Thursday") == 0) {
      day = Thursday;
   } else if (strcmp(day_of_week, "Friday") == 0) {
      day = Friday;
   } else {
      day = Saturday;
   } 

   if (strcmp(week, "first") == 0) {
      start = 1;
   } else if (strcmp(week, "second") == 0) {
      start = 8;
   } else if (strcmp(week, "teenth") == 0) {
      start = 13;
   } else if (strcmp(week, "third") == 0) {
      start = 15;
   } else if (strcmp(week, "fourth") == 0) {
      start = 22;
   } else {
      start = 0;
      dir = -1;
      month += 1;
   }

   struct tm date = {.tm_year=year, .tm_mon=month-1, .tm_mday=start};
   
   for (mktime(&date); date.tm_wday != day; date.tm_mday += dir, mktime(&date));

   return date.tm_mday;
}
