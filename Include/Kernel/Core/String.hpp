#pragma once

#include <Kernel/Debug.hpp>
#include <Kernel/Core/StringView.hpp>

namespace core
{

template<class CharType>
class BasicString
{
public:
    static auto create() -> BasicString;
    static auto from(const char *str) -> BasicString;
    static auto from(core::StringView str) -> BasicString;
private:
    u8 *buffer;
    usize length;
    usize capacity;

    BasicString();
    BasicString(core::StringView str);
};

using String = BasicString<char>;

template<class C>
auto BasicString<C>::create() -> BasicString
{
    return BasicString{};
}

template<class C>
auto BasicString<C>::from(const char *str) -> BasicString
{
    return BasicString{core::StringView::from(str)};   
}

template<class C>
auto BasicString<C>::from(core::StringView str) -> BasicString
{
    return BasicString{str};
}

template<class C>
BasicString<C>::BasicString()
{
    KERNEL_DEBUG_TODO();
}

template<class C>
BasicString<C>::BasicString(core::StringView str)
{
    KERNEL_DEBUG_TODO();
}

}