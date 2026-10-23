#pragma once

#include <Kernel/Core/TypeTraits.hpp>

namespace core
{
    template<class T>
    constexpr traits::RemoveReference<T>&& Move(T&& t)
    {
        return static_cast<typename traits::RemoveReference<T>&&>(t);
    }
}