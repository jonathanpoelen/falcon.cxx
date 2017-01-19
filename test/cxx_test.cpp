#include "falcon/cxx/cxx.hpp"
#include "falcon/cxx/compiler_attributes.hpp"
#include "falcon/cxx/lib.hpp"
#include "falcon/cxx/lib_experimental.hpp"
#include "falcon/cxx/move_algorithm.hpp"
#include "falcon/cxx/move.hpp"

template<class... T>
void foo(T... x)
{
  static_assert(noexcept(FALCON_UNPACK(x+1)), "must be noexcept");
}

int main()
{
  foo(1, 2);
}
