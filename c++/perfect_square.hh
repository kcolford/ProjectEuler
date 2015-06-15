#ifndef PERFECT_SQUARE_HH
#define PERFECT_SQUARE_HH

#include "attributes.h"

// Return the integer square root of s or 0 if it is not a perfect
// square.
unsigned int_sqrt(unsigned s)
  ATTRIBUTE_CONST
  ;

// Return whether or not s is a perfect square.
bool is_perfect_square(unsigned s)
  ATTRIBUTE_CONST
  ;

// Return whether or not s is a perfect square.
//
// If s is in fact a perfect square then sets s to to its square root.
bool set_int_sqrt(unsigned& s)
  ;

// Return a number such that there exists another number such that
// their sum is s and their product is p.
//
// If no such number exists, return 0.
int sp_val(int s, int p)
  ATTRIBUTE_CONST
  ;

// Return whether or not there exists two integers whose sum is s and
// product is p.
//
// If those numbers exist, then set s and p to their value.
bool sum_product(int& s, int& p)
  ;

#endif
