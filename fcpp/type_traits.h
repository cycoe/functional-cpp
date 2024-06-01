#ifndef __FCPP_TYPE_TRAITS__
#define __FCPP_TYPE_TRAITS__

#include <type_traits>

template <typename T, typename... Ts> struct is_one_of;

template <typename T, typename Tt, typename... Ts>
struct is_one_of<T, Tt, Ts...> {
  static constexpr bool value =
      std::is_same<T, Tt>::value || is_one_of<T, Ts...>::value;
};

template <typename T> struct is_one_of<T> {
  static constexpr bool value = false;
};

template <bool v, bool... vs>
struct any_of {
  static constexpr bool value = v || any_of<vs...>::value;
};

template <bool v> struct any_of<v> {
  static constexpr bool value = v;
};

#endif /* __FCPP_TYPE_TRAITS__ */
