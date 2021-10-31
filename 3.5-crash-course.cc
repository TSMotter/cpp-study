// Course available @ https://github.com/rougier/CPP-Crash-Course

#include <iostream>

class Animal
{
  public:
    Animal()
    {}
  
    void Move()
    {
      std::cout << "I'm a moving animal" << std::endl;
    }

    // This method returns a reference to an object, 
    // so yes, it's possible to do foo.method1().method2()
    Animal &Dummy (void)
    {
      return *this;
    }
};

int main(int argc, char **argv)
{
  Animal cat;

  cat.Dummy().Move();

  return 0;
}