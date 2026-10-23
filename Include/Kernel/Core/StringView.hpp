#pragma once

#include <Kernel/Debug.hpp>

namespace core
{

template<class CharType>
class BasicStringView
{
public:
    constexpr static auto from(const CharType *str) -> BasicStringView
    {
        return BasicStringView{str};
    }

    constexpr auto length() -> usize const { return length_; }
    constexpr auto as_ptr() -> CharType * const { return str; }
    constexpr auto as_bytes() -> const u8 * const { return reinterpret_cast<const u8 *>(str); }
    constexpr const CharType& operator[](usize index) const { return str[index]; }
private:
    const CharType *str;
    usize length_;

    constexpr BasicStringView(const CharType *str);
};

using StringView = BasicStringView<char>;

template<class CharType>
constexpr BasicStringView<CharType>::BasicStringView(const CharType *str)
{
    KERNEL_DEBUG_TODO();
}

}