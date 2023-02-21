/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a functor class
*/

#include <iostream>
#include <cassert>

class add_x
{
   public:
    // Default ctor
    add_x(int val) : x(val)
    {
        std::cout << "Default ctor called" << std::endl;
    }

    /*
      Operator "()" overloading. This is what makes this class a functor

      This is a "const function", which means that this method is not allowed to
      change any member variable of the class (x, in this case)
    */
    int operator()(int y) const
    {
        return x + y;
    }

   private:
    int x;
};

int main(int argc, char **argv)
{
    // Create an instance of the functor class
    add_x add42(42);
    // And "call" it
    int i = add42(8);
    // And it added 42 to its argument
    assert(i == 50);

    return 0;
}