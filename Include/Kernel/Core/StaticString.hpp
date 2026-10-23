#pragma once

#include <Kernel/Core/Math.hpp>
#include <Kernel/Core/Mem.hpp>
#include <Kernel/Core/StringView.hpp>
#include <Kernel/Core/TypeTraits.hpp>

namespace core
{

template<class CharType, usize Capacity>
class BasicStaticString
{
public:
    static constexpr auto create() -> BasicStaticString;
    static constexpr auto from(const char *str) -> BasicStaticString;
    static constexpr auto from(StringView str) -> BasicStaticString;

    constexpr auto length() -> usize const { return length_; }
private:
    CharType buffer[Capacity] = {};
    usize length_;

    constexpr BasicStaticString();
    constexpr BasicStaticString(const char *str);
    constexpr BasicStaticString(StringView str);
};

template<usize Capacity>
using StaticString = BasicStaticString<char, Capacity>;

template<class C, usize Capacity>
constexpr auto BasicStaticString<C, Capacity>::create() -> BasicStaticString
{
    return BasicStaticString{};
}

template<class C, usize Capacity>
constexpr auto BasicStaticString<C, Capacity>::from(const char *str) -> BasicStaticString
{
    return BasicStaticString{StringView::from(str)};   
}

template<class C, usize Capacity>
constexpr auto BasicStaticString<C, Capacity>::from(StringView str) -> BasicStaticString
{
    return BasicStaticString{str};
}

template<class C, usize Capacity>
constexpr BasicStaticString<C, Capacity>::BasicStaticString(StringView str)
: length_{math::Min(str.length(), Capacity)}
{
    if consteval
    {
        for (usize i = 0; i < length_; i++)
        {
            buffer[i] = str[i];
        }
    }
    else
    {
        Memcpy(buffer, str.as_bytes(), length_);
    }
}

}