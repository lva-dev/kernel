#pragma once

#include <Kernel/Core/Utility.hpp>

namespace core
{

void *Memcpy(void *dst, const void *src, usize size);

namespace mem
{

template<class T>
class Storage
{
public:
    constexpr inline static usize SIZE = sizeof(T);

    constexpr Storage() = default;

    static constexpr auto initialized(T&& value)
    {
        return Storage{Move(value)};
    }

    constexpr T *ptr()
    {
        return reinterpret_cast<T *>(&storage_);
    }
    
    constexpr const T *ptr() const
    {
        return reinterpret_cast<T *>(&storage_);
    }
    
    constexpr T& ref()
    {
        return *ptr();
    }

    constexpr const T& ref() const
    {
        return *ptr();
    }
private:
    u8 storage_[SIZE];

    Storage(T&& value) : storage_{}
    {
        u8 *ptr = reinterpret_cast<u8 *>(&value);
        Memcpy(storage_, ptr, SIZE);
    }
};

}

}