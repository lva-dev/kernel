#pragma once

#include <Kernel/Debug.hpp>
#include <Kernel/Structures/Chain.hpp>

namespace ds
{

namespace chained
{

template<class T>
class LinkedListChain
{
public:
    static auto create(T& object) -> LinkedListChain
    {
        return LinkedListChain{object};
    }
private:
    // TODO: Add more
    detail::ChainBase<T> base;

    LinkedListChain(T& object) : base{detail::ChainBase<T>::create(object)} {}
};

template<class T>
class LinkedList
{
public:
    using Chain = LinkedListChain<T>;
    
    constexpr static auto create() -> LinkedList
    {
        return LinkedList{};
    }

    auto push([[maybe_unused]] Chain& chain) -> void
    {
        KERNEL_DEBUG_TODO();
    }
private:
    LinkedList() = default;
};

}

}
