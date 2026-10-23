#pragma once

namespace core::math
{

template<class T>
T Min(const T a, const T b)
{
    return (a > b) ? b : a;
}

}