#pragma once

#include <Kernel/Core/Optional>
#include <Kernel/Sched/Sched.hpp>
#include <Kernel/Structures/ChainedLinkedList.hpp>

namespace sched
{

struct Thread;

class ThreadList
{
public:
    using List = ds::chained::LinkedList<Thread>;
    using Chain = List::Chain;
    
    static auto push(Chain& thread) -> void;
private:
    constinit static core::Optional<List> list;

    static auto init() -> void;

    friend auto sched::init() -> void;
};

}