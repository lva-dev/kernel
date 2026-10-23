#include <Kernel/Core/Expected.hpp>
#include <Kernel/Core/String.hpp>
#include <Kernel/Core/StringView.hpp>
#include <Kernel/Sched/Thread.hpp>
#include <Kernel/Sched/ThreadList.hpp>

core::Expected<i32, core::String> kernel_main() {
    sched::init();
    [[maybe_unused]] auto thread = sched::Thread::create(core::StringView::from("abc"));
    return core::ok<i32>(0);
}

extern "C" void kernel_start()
{
    auto result = kernel_main();
    if (result.is_err())
    {
        // Error
    }
    else
    {
        // Report exit code
    }
}