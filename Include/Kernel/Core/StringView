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

    constexpr auto length() const -> usize { return length_; }
    constexpr auto as_ptr() const -> const CharType * { return str; }
    constexpr auto as_bytes() const -> const u8 * { return reinterpret_cast<const u8 *>(str); }
    constexpr auto operator[](usize index) const -> const CharType& { return str[index]; }
private:
    const CharType *str;
    usize length_;

    constexpr BasicStringView(const CharType *str);
};

using StringView = BasicStringView<char>;

template<class CharType>
constexpr BasicStringView<CharType>::BasicStringView([[maybe_unused]] const CharType *str)
{
    KERNEL_DEBUG_TODO();
}

}