#ifndef FIXED_STL_VECTOR_HH
#define FIXED_STL_VECTOR_HH

// Bring in the original vector header.
#include <vector>

// Support headers.
#include <algorithm>
#include <iterator>
#include <ostream>

// Configuration macros.
#ifndef VECTOR_INDENT
#define VECTOR_INDENT "  "
#endif
#ifndef VECTOR_DELIM
#define VECTOR_DELIM ", "
#endif
#ifndef VECTOR_ROWS
#define VECTOR_ROWS 8
#endif
#ifndef VECTOR_MULTILINE_THRESHOLD
#define VECTOR_MULTILINE_THRESHOLD 100
#endif

template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T, A>& v)
{
  out << "{";
  if (!v.empty()) {
    if (v.size() < VECTOR_MULTILINE_THRESHOLD) {
      std::copy(v.begin(), v.end() - 1,
                std::ostream_iterator<T>(out, VECTOR_DELIM));
      out << v.back();
    } else {
      out << std::endl;
      int i;
      for (i = VECTOR_ROWS; i < v.size() - 1; i += VECTOR_ROWS) {
        out << VECTOR_INDENT;
        for (int j = i - VECTOR_ROWS; j < i; j++)
          out << v[j] << VECTOR_DELIM;
        out << std::endl;
      }
      out << VECTOR_INDENT;
      for (i -= VECTOR_ROWS; i < v.size() - 1; i++)
        out << v[i] << VECTOR_DELIM;
      out << v[i] << std::endl;
    }
  }
  out << "}";
  return out;
}

#endif
