// limiter.cc -- sets up time/memory limits at load time.

#include "error_check.hh"
#include <iostream>
#include "limiter.hh"
#include <sys/resource.h>
#include <sys/time.h>

Limiter& Limiter::create()
{
  static Limiter l;
  return l;
}

Limiter::Limiter()
{
  struct rlimit lim;
    
#define ADJUST_LIMIT(resource, val) do {        \
    ERROR_CHECK(getrlimit, resource, &lim);     \
    lim.rlim_cur = (val);                       \
    ERROR_CHECK(setrlimit, resource, &lim);     \
  } while (0)

#undef RLIM_INFINITY
#define RLIM_INFINITY lim.rlim_max
    
  // Programs should complete within 60s
  ADJUST_LIMIT(RLIMIT_CPU, 60);

  // We'll restrict the address space to 32MB.
  ADJUST_LIMIT(RLIMIT_DATA, 32 * 1024 * 1024);

  // Allow core dumps.
  ADJUST_LIMIT(RLIMIT_CORE, RLIM_INFINITY);

#if 0
  std::cout << "limits set" << std::endl;
#endif
}
