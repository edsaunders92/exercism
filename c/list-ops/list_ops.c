#include "list_ops.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
   list_t * list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
   for (size_t i = 0; i < length; i++) {
      list->elements[i] = elements[i];
   }
   list->length = length;
   return list;
}

list_t * duplicate_list(list_t * list) {
   return new_list(list->length, list->elements);
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
   list_t * list = malloc(sizeof(list_t) + (list1->length + list2->length) * sizeof(list_element_t));

   list->length = list1->length + list2->length;
   for (size_t i = 0; i < list1->length; i++) {
      list->elements[i] = list1->elements[i];
   }
   for (size_t i = 0; i < list2->length; i++) {
      list->elements[i + list1->length] = list2->elements[i];
   }
   return list;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
   int length = 0;
   for (size_t i = 0; i < list->length; i++) {
      if (filter(list->elements[i])) {
         length++;
      } 
   }

   list_t * newlist = new_list(length, list->elements);

   int insert_index = 0;
   for (size_t i = 0; i < list->length; i++) {
      if (filter(list->elements[i])) {
         newlist->elements[insert_index] = list->elements[i];
         insert_index++;
      } 
   }
   return newlist;
}

// returns the length of the list
size_t length_list(list_t *list) {
   return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
   list_t * new_list = duplicate_list(list);
   for (size_t i = 0; i < new_list->length; i++) {
      new_list->elements[i] = map(new_list->elements[i]);
   }
   return new_list;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
   for (size_t i = 0; i < list->length; i++) {
      initial = foldl(list->elements[i], initial);
   }
   return initial;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
   for (size_t i = 0; i < list->length; i++) {
      initial = foldr(list->elements[list->length - i - 1], initial);
   }
   return initial;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
   list_t * new_list = duplicate_list(list);
   for (size_t i = 0; i < list->length; i++) {
      new_list->elements[i] = list->elements[list->length - 1 - i];
   }
   return new_list;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
   free(list);
}




