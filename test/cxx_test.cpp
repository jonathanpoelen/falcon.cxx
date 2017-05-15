#include "falcon/cxx/cxx.hpp"
#include "falcon/cxx/compiler_version.hpp"
#include "falcon/cxx/compiler_attributes.hpp"
#include "falcon/cxx/lib.hpp"
#include "falcon/cxx/lib_experimental.hpp"
#include "falcon/cxx/move_algorithm.hpp"
#include "falcon/cxx/move.hpp"

template<class... T>
FALCON_CONSTEXPR int foo(T... x)
{
  static_assert(noexcept(FALCON_UNPACK(x+1)), "must be noexcept");
  int sum = 0;
  FALCON_UNPACK(sum += x);
  return sum;
}

template<int i> class i_{};

int main()
{
#if FALCON_COMP_MSVC
  i_<foo(1, 2)>{};
#else
  if (foo(1, 2) != 3) throw 1;
#endif
}
