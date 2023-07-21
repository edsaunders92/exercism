#include "test-framework/unity.h"
#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int16_t write(__attribute__((unused)) circular_buffer_t* buffer, __attribute__((unused)) buffer_value_t value) {
   if (buffer->is_full) {
      errno = ENOBUFS;
      return EXIT_FAILURE;
   }
   buffer->values[buffer->write_index] = value;

   buffer->write_index += 1;
   buffer->write_index = buffer->write_index % buffer->capacity;

   buffer->is_full = (buffer->read_index == buffer->write_index);


   buffer->is_empty = false;
   return 0;
}

int16_t overwrite(__attribute__((unused)) circular_buffer_t* buffer,__attribute__((unused)) buffer_value_t value) {
   buffer->values[buffer->write_index] = value;

   buffer->write_index += 1;
   buffer->write_index = buffer->write_index % buffer->capacity;

   if (buffer->is_full) {
      buffer->read_index += 1;
      buffer->read_index = buffer->read_index % buffer->capacity;
   } else {
      buffer->is_full = (buffer->read_index == buffer->write_index);
   }

   buffer->is_empty = false;
   return 0;
}

int16_t read(__attribute__((unused)) circular_buffer_t* buffer,__attribute__((unused)) buffer_value_t* value) {
   if (buffer->is_empty) {
      errno = ENODATA;
      return EXIT_FAILURE;
   }
   *value = buffer->values[buffer->read_index];

   buffer->read_index += 1;
   buffer->read_index = buffer->read_index % buffer->capacity;
   buffer->is_full = false;
   buffer->is_empty = buffer->read_index == buffer->write_index;
   return 0;
}

void clear_buffer(__attribute__((unused)) circular_buffer_t* buffer) {
   buffer->read_index = 0;
   buffer->write_index = 0;
   buffer->is_full = buffer->capacity == 0;
   buffer->is_empty = true;
}

void delete_buffer(circular_buffer_t* buffer){
   free(buffer);
}

circular_buffer_t* new_circular_buffer(size_t capacity) {
   circular_buffer_t* buffer = malloc(sizeof(circular_buffer_t) + capacity * sizeof(buffer_value_t));
   buffer->capacity = capacity;
   clear_buffer(buffer);

   return buffer;
}
