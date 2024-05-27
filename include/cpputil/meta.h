#pragma once

namespace details {
    template <typename, template <typename...> typename>
    struct is_instantiation_of {};

    template <template <typename...> typename U, typename...Ts>
    struct is_instantiation_of<U<Ts...>, U> { static constexpr bool value = true; };
}

template<typename T, template<typename...> typename U>
concept instantiation_of = details::is_instantiation_of<T, U>::value;
