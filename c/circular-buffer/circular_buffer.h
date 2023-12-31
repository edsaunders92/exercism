#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdlib.h>

typedef int buffer_value_t;

typedef struct circular_buffer_t {
    size_t capacity;
    size_t read_index;
    size_t write_index;
    bool is_full;
    bool is_empty;
    buffer_value_t values[];
} circular_buffer_t;


int16_t write(circular_buffer_t* buffer, buffer_value_t value);

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value);

int16_t read(circular_buffer_t* buffer, buffer_value_t* value);

void clear_buffer(circular_buffer_t* buffer);

void delete_buffer(circular_buffer_t* buffer);

circular_buffer_t* new_circular_buffer(size_t capacity);

#endif
