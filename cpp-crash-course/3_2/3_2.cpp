/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Foo class with default and copy constructors and add also an
  assignment operator. Write some code to highlight the use of each of them.
*/

#include <iostream>

class Foo_c
{
 public:
  // Default ctor (initialization list)
  Foo_c(int argc = 0) : x(argc)
  {
    std::cout << "Default ctor called" << std::endl;
  }

  // Copy ctor
  Foo_c(const Foo_c &obj)
  {
    std::cout << "Copy ctor called" << std::endl;
  }

  // Default dtor
  ~Foo_c(void)
  {
    std::cout << "Default dtor called" << std::endl;
  }

  // Overloading the assignment operator "="
  Foo_c &operator=(const Foo_c &obj)
  {
    std::cout << "Operator overload called" << std::endl;
    x = obj.x;
    return *this;
  }

 private:
  int x;
};

int main(int argc, char **argv)
{
  std::cout << "Test constructors:" << std::endl;
  // Tests the copy constructor:
  // -> this calls default ctor:
  Foo_c obj1(10);
  // -> these call copy ctor:
  Foo_c obj2 = obj1;
  Foo_c obj3(obj2);

  std::cout << "-----------------------" << std::endl;

  std::cout << "Test operation overload:" << std::endl;
  // Tests the assingment operator overload:
  Foo_c obj5;
  obj5 = obj1;

  std::cout << "-----------------------" << std::endl;

  return 0;
}