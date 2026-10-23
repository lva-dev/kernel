#include <Kernel/Debug.hpp>
#include <Kernel/Sched/ThreadList.hpp>

using List = sched::ThreadList::List;

namespace sched
{

constinit core::Optional<List> ThreadList::list = core::none();

auto ThreadList::push(Chain& thread) -> void
{
    KERNEL_DEBUG_ASSERT(list.has_value(), "Oops!");
    list->push(thread);
}

auto ThreadList::init() -> void
{
    list = core::some(List::create());
}

}