#include <Kernel/Debug.hpp>

namespace core::memory
{

void *Memcpy(void *dest, const void *src, usize size)
{
    KERNEL_DEBUG_ASSERT(dst_ != nullptr || size == 0);
    KERNEL_DEBUG_ASSERT(src_ != nullptr || size == 0);
    
    u8 *dst_ = static_cast<u8 *>(dest);
    const u8 *src_ = static_cast<const u8 *>(src);
    while (size-- > 0)
    {
        *dst_++ = *src_++;
    }

    return dest;
}

}