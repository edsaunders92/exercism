#ifndef DARTS_H
#define DARTS_H

typedef struct coordinate_t {
    float x, y;
} coordinate_t;

int score(struct coordinate_t landing_position);
#endif
