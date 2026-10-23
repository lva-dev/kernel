#include <Kernel/Sched/Sched.hpp>
#include <Kernel/Sched/ThreadList.hpp>

namespace sched
{

auto init() -> void
{
    ThreadList::init();
}

}