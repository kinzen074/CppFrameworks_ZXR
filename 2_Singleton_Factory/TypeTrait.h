#pragma once

#define DEFINE_TYPE_TRAIT(name, func)                          \
  /*Check if Class has func return true*/                      \
  template <typename T>                                        \
  struct name {                                                 \
    template <typename Class>                                   \
    static constexpr bool Test(decltype(&Class::func)*) {       \
      return true;                                             \
    }                                                          \
                                                               \
    /*Else return false*/                                      \
    template <typename>                                        \
    static constexpr bool Test(...) {                          \
      return false;                                            \
    }                                                          \
                                                               \
    /*Result*/                                                 \
    static constexpr bool value = Test<T>(nullptr);            \
  };                                                           \
                                                               \
  template <typename T>                                        \
  constexpr bool name<T>::value;         