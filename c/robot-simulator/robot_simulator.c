#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {

   robot_position_t position = { x , y};
   robot_status_t status = { direction, position };

   return status;
}

void robot_move(robot_status_t *robot, const char *commands) {
   for (; *commands; commands++) {
      if (*commands == 'R') {
         robot->direction++;
         if (robot->direction == DIRECTION_MAX) {
            robot->direction = DIRECTION_DEFAULT;
         }
      }
      if (*commands == 'L') {
         if (robot->direction == DIRECTION_DEFAULT) {
            robot->direction = DIRECTION_MAX;
         }
         robot->direction--;
      }
      if (*commands == 'A') {
         if (robot->direction == DIRECTION_NORTH) {
            robot->position.y += 1;
         }
         if (robot->direction == DIRECTION_EAST) {
            robot->position.x += 1;
         }
         if (robot->direction == DIRECTION_SOUTH) {
            robot->position.y -= 1;
         }
         if (robot->direction == DIRECTION_WEST) {
            robot->position.x -= 1;
         }
      }
   }
}

