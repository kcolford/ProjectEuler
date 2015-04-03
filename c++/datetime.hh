#ifndef DATETIME_HH
#define DATETIME_HH

#include "attributes.h"

bool is_leap_year(int year)
  ATTRIBUTE_CONST
  ATTRIBUTE_LEAF
  ;

int days_in_month(int year, int month)
  ATTRIBUTE_CONST
  ATTRIBUTE_FLATTEN
  ;

int days_in_year(int year)
  ATTRIBUTE_CONST
  ATTRIBUTE_FLATTEN
  ;

#endif
