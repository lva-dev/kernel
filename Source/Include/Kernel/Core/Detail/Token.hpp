#pragma once

namespace core::detail::token
{

template<class T, class Implementor>
class Token
{
public:
    static constexpr auto create(T&& value) -> Implementor { return Implementor{Move(value)}; }

    constexpr auto value() -> T&
    {
        return value_;
    }
protected:
    constexpr Token(T&& value) : value_{Move(value)} {}
private:
    T value_;
};

}