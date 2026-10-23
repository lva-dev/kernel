#pragma once

namespace ds::chained::detail
{

template<class T>
class ChainBase
{
public:
    static auto create(T& object) -> ChainBase
    {
        return ChainBase{object};
    }
private:
    T *object;

    ChainBase(T& object) : object{&object} {}
};

}