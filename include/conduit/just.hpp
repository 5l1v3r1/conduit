#ifndef CONDUIT_JUST_HPP
#define CONDUIT_JUST_HPP

#include "meta.hpp"
#include "seq.hpp"
#include <array>
#include <type_traits>

namespace conduit {

template<class...Xs>
auto just(Xs...xs) {
  if constexpr(sizeof...(xs)>0) {
    using T = std::common_type_t<decltype(xs)...>;
    return [=]() -> seq<T> {
      T data[] = {(T)xs...};
      for( auto x: data) {
        co_yield x;
      }
    };
  } else {
    return []() -> seq<int> {
      co_return;
    };
  }
}
}

#endif
