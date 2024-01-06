#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>

#include "concepts.hpp"

namespace cst
{
    template<SignedIntegral T>
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

    template<UnsignedIntegral T>
    constexpr auto str_to_uint(std::string_view str) noexcept -> T
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
        return val;
    }

    template<Floating T>
    constexpr auto average(const std::vector<T>& vec) -> T
    {
        if (vec.empty()) {
            return 0;
        }
    
        const auto count = static_cast<T>(vec.size());
        return std::reduce(vec.begin(), vec.end()) / count;
    }

    constexpr auto str_to_i16(std::string_view str) noexcept -> std::int16_t
    {
        return str_to_int<std::int16_t>(str);
    }

    constexpr auto str_to_i32(std::string_view str) noexcept -> std::int32_t
    {
        return str_to_int<std::int32_t>(str);
    }

    constexpr auto str_to_i64(std::string_view str) noexcept -> std::int64_t
    {
        return str_to_int<std::int64_t>(str);
    }

    constexpr auto str_to_u16(std::string_view str) noexcept -> std::uint16_t
    {
        return str_to_uint<std::uint16_t>(str);
    }

    constexpr auto str_to_u32(std::string_view str) noexcept -> std::uint32_t
    {
        return str_to_uint<std::uint32_t>(str);
    }

    constexpr auto str_to_u64(std::string_view str) noexcept -> std::uint64_t
    {
        return str_to_uint<std::uint64_t>(str);
    }

    constexpr auto str_split(const std::string& str,
                             const std::string& delimiter = " ") -> std::vector<std::string>
    {
        using std::string;
        std::vector<string> result;
        string::size_type begin = 0;
        while (true) {
            const auto end = str.find(delimiter, begin);
            const auto token = str.substr(begin, end - begin);
            result.push_back(token);
            if (end == string::npos) {
                break;
            }
            begin = end + delimiter.length();
        }
        return result;
    }
}; // end namespace cst
