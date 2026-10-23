#pragma once

#include <Kernel/Core/StaticString.hpp>
#include <Kernel/Core/StringView.hpp>
#include <Kernel/Sched/ThreadList.hpp>

namespace sched
{

struct Thread
{
public:
    static auto create(core::StringView name) -> Thread
    {
        return Thread{name};
    }
    
private:
    core::StaticString<256> name_;
    ThreadList::Chain thread_list_chain = ThreadList::Chain::create(*this);

    Thread(core::StringView name);
};

}