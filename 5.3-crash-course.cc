/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a correct division function.
*/

#include <iostream>
#include <stdexcept>

class bad_denominator : public std::runtime_error
{
  /*
    std::runtime_error is a more specialized class than std::exception,
    that descends from std::exception, intended to be thrown in case of various
    runtime errors. It has a dual purpose. It can be thrown by itself, or it can
    serve as a base class to various even more specialized types of runtime
    error exceptions, such as std::range_error, std::overflow_error etc. You can
    define your own exception classes descending from std::runtime_error, as
    well as you can define your own exception classes descending from
    std::exception.

    This allows the user to design it's own exception hierarchy, since catch
    works for polymorphic exceptions.
  */
 public:
  bad_denominator(void) : std::runtime_error("Bad denominator")
  {
    std::cout << "Default ctor called" << std::endl;
  }
};

float correct_divide(float num, float den)
{
  if (den == 0)
  {
    throw bad_denominator();
  }

  return (num / den);
}

int main(int argc, char** argv)
{
  correct_divide(10, 0);

  return 0;
}