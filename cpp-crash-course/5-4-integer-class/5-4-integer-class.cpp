/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Integer (positive) class with proper exception handling (Overflow,
  Underflow, DivideByZero, etc.)
*/

#include <iostream>
#include <stdexcept>

struct DivideByZero : public std::runtime_error
{
    DivideByZero(void) : std::runtime_error("DivideByZero")
    {
    }
};

struct OverflowError : public std::runtime_error
{
    OverflowError(void) : std::runtime_error("OverflowError")
    {
    }
};

struct UnderflowError : public std::runtime_error
{
    UnderflowError(void) : std::runtime_error("UnderflowError")
    {
    }
};

class Integer
{
   public:
    Integer(int value) : m_value(value)
    {
        std::cout << "Integer default constructor" << std::endl;
    }
    ~Integer()
    {
        std::cout << "Integer default destructor" << std::endl;
    }

    Integer &operator=(const Integer &other)
    {
        std::cout << "Operator= overload" << std::endl;
        m_value = other.m_value;
        return *this;
    }

    Integer operator+(const Integer &other)
    {
        std::cout << "Operator+ overload" << std::endl;

        int tmp = this->m_value + other.m_value;
        if (tmp >= overflow_limit)
        {
            throw OverflowError();
        }

        return Integer(tmp);
    }

    Integer operator-(const Integer &other)
    {
        std::cout << "Operator- overload" << std::endl;

        int tmp = this->m_value - other.m_value;
        if (tmp < underflow_limit)
        {
            throw UnderflowError();
        }

        return Integer(tmp);
    }

    Integer operator*(const Integer &other)
    {
        std::cout << "Operator* overload" << std::endl;

        int tmp = this->m_value * other.m_value;
        if (tmp >= overflow_limit)
        {
            throw OverflowError();
        }

        return Integer(tmp);
    }

    Integer operator/(const Integer &other)
    {
        std::cout << "Operator/ overload" << std::endl;

        if (other.m_value == 0)
        {
            throw DivideByZero();
        }

        return Integer(this->m_value / other.m_value);
    }

    friend std::ostream &operator<<(std::ostream &output, Integer &obj)
    {
        std::cout << "Operator<< overload" << std::endl;
        return output << obj.m_value;
    }

   private:
    int              m_value;
    static const int overflow_limit  = 100;
    static const int underflow_limit = 0;
};

int main(int argc, char **argv)
{
    Integer res{0}, foo{0}, bar{80}, giz{81};

    // Overflow
    /* res = bar + giz;
    std::cout << "res (+) = " << res << std::endl;
    res = 0; */

    // Underflow
    /* res = bar - giz;
    std::cout << "res (-) = " << res << std::endl;
    res = 0; */

    // Divide by zero
    res = bar / foo;
    std::cout << "res (/) = " << res << std::endl;
    res = 0;

    return 0;
}