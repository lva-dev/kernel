#pragma once

namespace core::traits
{

template<class T> struct RemoveReferenceStruct { typedef T type; };
template<class T> struct RemoveReferenceStruct<T&> { typedef T type; };
template<class T> struct RemoveReferenceStruct<T&&> { typedef T type; };

template<class T>
using RemoveReference = typename RemoveReferenceStruct<T>::type;

}