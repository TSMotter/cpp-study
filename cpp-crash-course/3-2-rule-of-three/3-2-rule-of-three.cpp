/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Foo class with default and copy constructors and add also an
  assignment operator. Write some code to highlight the use of each of them.
*/

#include <iostream>

class Foo
{
   public:
    // Default ctor (initialization list)
    Foo(int var = 0) : m_var(var)
    {
        std::cout << "Default ctor called" << std::endl;
    }

    // Copy ctor
    Foo(const Foo &obj)
    {
        std::cout << "Copy ctor called" << std::endl;
    }

    // Default dtor
    ~Foo()
    {
        std::cout << "Default dtor called" << std::endl;
    }

    // Overloading the assignment operator "="
    Foo &operator=(const Foo &obj)
    {
        std::cout << "Operator overload called" << std::endl;
        m_var = obj.m_var;
        return *this;
    }

   private:
    int m_var;
};

int main(int argc, char **argv)
{
    std::cout << "Test constructors:" << std::endl;

    // Tests the copy constructor:
    // -> this calls default ctor:
    Foo obj1{10};
    // -> these call copy ctor:
    Foo obj2 = obj1;
    Foo obj3{obj2};

    std::cout << "-----------------------" << std::endl;

    std::cout << "Test operation overload:" << std::endl;
    // Tests the assingment operator overload:
    Foo obj5;
    obj5 = obj1;

    std::cout << "-----------------------" << std::endl;

    return 0;
}