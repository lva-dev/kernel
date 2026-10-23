#include <Kernel/Sched/Thread.hpp>
#include <Kernel/Sched/ThreadList.hpp>

namespace sched
{

Thread::Thread(core::StringView name) : name_{core::StaticString<256>::from(name)} {
    ThreadList::push(thread_list_chain);
}

}