#pragma once

#include <concepts>

template<class T>
concept Integral = std::is_integral_v<T>;

template<class T>
concept SignedIntegral = Integral<T> && std::is_signed_v<T>;

template<class T>
concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

template<class T>
concept Floating = std::is_floating_point_v<T>;

