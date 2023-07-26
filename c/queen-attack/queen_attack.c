#include "queen_attack.h"


attack_status_t can_attack(position_t queen_1, position_t queen_2) {
   if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
      return INVALID_POSITION;
   }

   if (queen_1.row < 0 || queen_1.row >= 8 || queen_1.column < 0 || queen_1.column >= 8 || queen_2.row < 0 || queen_2.row >= 8 || queen_2.column < 0 || queen_2.column >= 8) {
      return INVALID_POSITION;
   }


   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) {
            continue;
         }
         uint8_t row = queen_1.row + i;
         uint8_t col  = queen_1.column + j;
         for (; row >= 0 && row < 8 && col >= 0 && col < 8; row += i, col += j) {
            if (row == queen_2.row && col == queen_2.column) {
               return CAN_ATTACK;
            }
         }
      }
   }
   return CAN_NOT_ATTACK;
}
