#ifndef __FCPP_FUNCTOR_H__
#define __FCPP_FUNCTOR_H__

#include <functional>
#include <utility>
#include <vector>

struct Functor;

template <typename F, template <typename> typename Container, typename T,
          typename = typename Container<T>::iterator>
inline auto fmap(F &&f, Container<T> const &c) {
  using Tt = decltype(f(std::declval<T>()));
  Container<Tt> res;
  res.reserve(c.size());
  for (auto const & e : c) {
    res.emplace_back(f(e));
  }
  return res;
}

#endif /* __FCPP_FUNCTOR_H__ */
