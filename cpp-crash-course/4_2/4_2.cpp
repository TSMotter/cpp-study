/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a foo function and make it called from a class that has a foo method.
*/

#include <iostream>

namespace my_namespace
{
void foo(void)
{
    std::cout << "foo function called" << std::endl;
}
}  // namespace my_namespace

class Foo_c
{
   public:
    Foo_c()
    {
        std::cout << "Default ctor called" << std::endl;
    }

    void foo(void)
    {
        my_namespace::foo();
    }
};

int main(int argc, char **argv)
{
    Foo_c obj1;

    obj1.foo();

    return 0;
}