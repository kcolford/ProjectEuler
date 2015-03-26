#ifndef LIMITER_HH
#define LIMITER_HH

class Limiter
{
  Limiter();
public:
  static Limiter& create();
};

static Limiter& _force_link_with_limiter = Limiter::create();

#endif
