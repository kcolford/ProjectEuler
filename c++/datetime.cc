// datetime.cc -- implementation of the datetime interface

#include <cassert>
#include "datetime.hh"

enum { DAYS_IN_REGULAR_YEAR = 365 };

bool is_leap_year(int year)
{
  return (year % 400 == 0 ? true :
          year % 100 == 0 ? false :
          year %   4 == 0 ? true :
                            false
          );
}

int days_in_month(int year, int month)
{
  assert(1 <= month && month <= 12);
  return 30 + (month + month / 8) % 2 + 
    (month == 2) * (is_leap_year(year) - 2);
}

int days_in_year(int year)
{
  return DAYS_IN_REGULAR_YEAR + is_leap_year(year);
}

