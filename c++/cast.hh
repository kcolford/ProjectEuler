#ifndef CAST_HH
#define CAST_HH

#include "attributes.h"
#include <gmpxx.h>
#include <limits>

template<typename T, typename V>
T cast(V v)
  ATTRIBUTE_CONST
  ;

template<typename T, typename V>
T cast(V v)
{
  return static_cast<T>(v);
}

template<typename T>
T cast(mpz_class m)
  ATTRIBUTE_PURE
  ;

template<typename T>
T cast(mpz_class m)
{
  return static_cast<T>(mpz_class(m % std::numeric_limits<T>::max()).get_si());
}

#endif
