#include "grade_school.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>                                                                         
#include <stdbool.h>
#include <string.h>

void init_roster(roster_t * roster) {
   roster->count = 0;
}

bool add_student(roster_t * roster, char name[], uint8_t grade) {

   for (size_t i = 0; i < roster->count; i++) {
      student_t * student = &roster->students[i];
      if (strcmp(student->name, name) == 0) {
         return false;
      }
   }

   // Find the insert index
   size_t i = 0;
   for (; i < roster->count; i++) {
      student_t * student = &roster->students[i];
      if (student->grade < grade) {
         continue;
      }
      if (student->grade > grade) {
         break;
      }
      if (strcmp(student->name, name) < 0) {
         continue;
      }
      break;
   }

   // i is the insertion point. Move every studen above i up one place
   for (size_t j = roster->count; j > i; j--) {
      roster->students[j+1] = roster->students[j];
   }
   roster->students[i].grade = grade;
   strcpy(roster->students[i].name, name);

   roster->count++;
   return true;
}

roster_t get_grade(roster_t * roster, int grade) {
   roster_t grade_roster;

   for (size_t i = 0; i < roster->count; i++) {
      student_t * student = &(roster->students[i]);
      if (student->grade == grade) {
         add_student(&grade_roster, student->name, student->grade);
      }
   }

   return grade_roster;
}
