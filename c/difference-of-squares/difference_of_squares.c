#include "difference_of_squares.h"

/**
 * @brief Calcultes the difference sum of the squares of the first N natural numbers.
 *
 * @link https://en.wikipedia.org/wiki/Square_pyramidal_number
 **/
unsigned int sum_of_squares(unsigned int number) {
   return (2 * number * number * number + 3 * number * number + number) / 6;
}

/**
 * @brief Calcultes the square of the sum of the first N natural numbers.
 *
 * Using geometric progression
 **/
unsigned int square_of_sum(unsigned int number) {
   return ((number * (number + 1)) / 2) * ((number * (number + 1)) / 2);
}

/**
 * @brief Calcultes the difference between the square of the sum and the sum of the squares of the first N natural numbers.
 **/
unsigned int difference_of_squares(unsigned int number) {
   return square_of_sum(number) - sum_of_squares(number);
}
