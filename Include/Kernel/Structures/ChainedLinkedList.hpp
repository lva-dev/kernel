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
    
    static auto create() -> LinkedList
    {
        KERNEL_DEBUG_UNIMPLEMENTED();
        return LinkedList{};
    }

    // TODO: Implement
    auto push(Chain& chain) -> void
    {
        KERNEL_DEBUG_UNIMPLEMENTED();
    }
private:
    LinkedList() = default;
};

}

}
