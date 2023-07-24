#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

typedef struct triplet_t {
    int a;
    int b;
    int c;
} triplet_t;

typedef struct triplets_t {
    int count; 
    triplet_t triplets[];
} triplets_t;

void free_triplets(triplets_t * triplet);

triplets_t * triplets_with_sum(int sum);

#endif
