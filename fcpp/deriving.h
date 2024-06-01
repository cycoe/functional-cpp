#ifndef __FCPP_DERIVING_H__
#define __FCPP_DERIVING_H__

#include "type_traits.h"

template <typename... Bases> struct deriving;

template <typename Base, typename Derived> struct is_base_of {
  static constexpr bool value = false;
};

template <typename Base, typename... Bases>
struct is_base_of<Base, deriving<Bases...>> {
  static constexpr bool value =
      is_one_of<Base, Bases...>::value ||
      any_of<is_base_of<Base, Bases>::value...>::value;
};

#endif /* __FCPP_DERIVING_H__ */
