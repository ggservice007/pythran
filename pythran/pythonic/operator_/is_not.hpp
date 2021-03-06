#ifndef PYTHONIC_OPERATOR_ISNOT_HPP
#define PYTHONIC_OPERATOR_ISNOT_HPP

#include "pythonic/include/operator_/is_not.hpp"

#include "pythonic/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace operator_
{

  template <class A, class B>
  auto is_not(A const &a, B const &b)
      -> decltype(builtins::id(a) != builtins::id(b))
  {
    return builtins::id(a) != builtins::id(b);
  }
}
PYTHONIC_NS_END

#endif
