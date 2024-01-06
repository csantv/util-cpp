#include "util.hpp"

template<class T>
constexpr auto str_to_int(std::string_view str) noexcept -> T
{
    const bool is_negative = str.front() == '-';
    if (is_negative) {
        str.remove_prefix(1);
    }
    T val = 0;
    const auto base10 = 10;
    for (const auto chr: str) {
        val = val * base10 + (chr - '0');
    }
    if (is_negative) {
        val *= -1;
    }
    return val;
}

constexpr auto cst::str_to_i16(std::string_view str) noexcept -> std::int16_t
{
    return str_to_int<std::int16_t>(str);
}

constexpr auto cst::str_to_i32(std::string_view str) noexcept -> std::int32_t
{
    return str_to_int<std::int32_t>(str);
}

constexpr auto cst::str_to_i64(std::string_view str) noexcept -> std::int64_t
{
    return str_to_int<std::int64_t>(str);
}


/*
constexpr auto cst::str_to_i16(std::string_view str) -> std::int16_t
{
    return str_to_int<std::int16_t>(str);
}

auto cst::str_to_i32(std::string_view str) -> std::int32_t
{
    return str_to_int<std::int32_t>(str);
}

auto cst::str_to_i64(std::string_view str) -> std::int64_t
{
    return str_to_int<std::int64_t>(str);
}

auto cst::str_to_u16(std::string_view str) -> std::uint16_t
{
    return str_to_int<std::uint16_t>(str);
}

auto cst::str_to_u32(std::string_view str) -> std::uint32_t
{
    return str_to_int<std::uint32_t>(str);
}

auto cst::str_to_u64(std::string_view str) -> std::uint64_t
{
    return str_to_int<std::uint64_t>(str);
}*/

