namespace core
{

void *Memcpy(void *dst, const void *src, usize size)
{
    u8 *dst_ = static_cast<u8 *>(dst);
    const u8 *src_ = static_cast<const u8 *>(src);

    // ASSERT(dst_ != nullptr || size == 0);
    // ASSERT(src_ != nullptr || size == 0);

    while (size-- > 0)
    {
        *dst_++ = *src_++;
    }

    return dst;
}

}