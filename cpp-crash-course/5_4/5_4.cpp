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


#define OVERFLOW_LIMIT 100

class Integer
{
   public:
    Integer(int in) : val(in)
    {
        std::cout << "Default Integer ctor called" << std::endl;
    }
    ~Integer()
    {
        std::cout << "Default Integer dtor called" << std::endl;
    }

    void Set(int x)
    {
        val = x;
    }

    int Get(void)
    {
        return val;
    }

    /*
      the object which will call this operator can be accessed using "this"
      key word. eg: <foo = bar + giz>; "bar" can be accessed here with "this",
      while "giz" can be accessed using the "obj" parameter
    */
    Integer operator+(const Integer &obj)
    {
        std::cout << "Operator '+' overload called" << std::endl;

        int temp = this->val + obj.val;
        if (temp >= OVERFLOW_LIMIT)
        {
            throw OverflowError();
        }

        return Integer(temp);
    }

    Integer operator-(const Integer &obj)
    {
        std::cout << "Operator '-' overload called" << std::endl;

        int temp = this->val - obj.val;
        if (temp < 0)
        {
            throw UnderflowError();
        }

        return Integer(temp);
    }

    Integer operator*(const Integer &obj)
    {
        std::cout << "Operator '*' overload called" << std::endl;

        int temp = this->val * obj.val;
        if (temp >= OVERFLOW_LIMIT)
        {
            throw OverflowError();
        }

        return Integer(temp);
    }

    Integer operator/(const Integer &obj)
    {
        std::cout << "Operator '/' overload called" << std::endl;

        if (obj.val == 0)
        {
            throw DivideByZero();
        }

        return Integer(this->val / obj.val);
    }

    // Operator "<<" overloading
    friend std::ostream &operator<<(std::ostream &output, Integer &obj)
    {
        std::cout << "Operator '<<' overload called" << std::endl;
        return output << " = " << obj.val;
    }

   private:
    int val;
};

int main(int argc, char **argv)
{
    Integer res(0), foo(0), bar(80), giz(81);

    // Overflow
    res = bar + giz;
    std::cout << "res (+) = " << res << std::endl;
    res.Set(0);

    // Underflow
    res = bar - giz;
    std::cout << "res (-) = " << res << std::endl;
    res.Set(0);

    // Divide by zero
    res = bar / foo;
    std::cout << "res (/) = " << res << std::endl;
    res.Set(0);

    return 0;
}