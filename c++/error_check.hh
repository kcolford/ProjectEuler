#ifndef ERROR_CHECK_HH
#define ERROR_CHECK_HH

#include <cerrno>
#include <cstring>
#include <sstream>
#include <stdexcept>

#define ERROR_CHECK(func, ...) do {             \
    if (func(__VA_ARGS__) < 0)  {               \
      std::stringstream ss;                     \
      ss << "In function "                      \
         << __func__                            \
         << ", error in call to "               \
         << #func                               \
        << ": "                                 \
        << std::strerror(errno)                 \
        ;                                       \
        throw std::runtime_error(ss.str());     \
    }                                           \
  } while (0)


#endif
