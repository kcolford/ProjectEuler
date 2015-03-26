// Utility header that includes all the usual headers and also exposes
// everything in the std namespace.

#ifdef UTIL_HH
# error util.hh should only be included once by an implementation file
#endif
#define UTIL_HH

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include "len.h"
#include "limiter.hh"
#include <sstream>
#include <string>
#include "vector.hh"

using namespace std;

