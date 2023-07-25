#include "allergies.h"
#include <stdio.h>
#include <stdlib.h>

bool is_allergic_to(allergen_t allergen, int allergies) {
   return (allergies & (1 << allergen)) > 0;
}

allergen_list_t get_allergens(int allergies) {
   allergen_list_t list;
   list.count = 0;

   for (int i = ALLERGEN_EGGS; i < ALLERGEN_COUNT; i++) {
      const bool has_allergy = is_allergic_to(i, allergies);
      list.allergens[i] = has_allergy;
      list.count += has_allergy;
   }
   return list;
}

