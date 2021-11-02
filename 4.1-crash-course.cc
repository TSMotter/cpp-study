/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Bar class that inherits from a Foo class and makes constructor and
  destructor methods to print something when called.
*/

#include <iostream>

class Foo
{
 public:
  Foo()
  {
    std::cout << "Default Foo ctor called" << std::endl;
  }

  ~Foo()
  {
    std::cout << "Default Foo dtor called" << std::endl;
  }
};

class Bar : public Foo
{
 public:
  Bar()
  {
    std::cout << "Default Bar ctor called" << std::endl;
  }

  ~Bar()
  {
    std::cout << "Default Bar dtor called" << std::endl;
  }
};

int main(int argc, char **argv)
{
  Bar baz;
  return 0;
}