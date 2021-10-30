// Course available @ https://github.com/rougier/CPP-Crash-Course

#include <iostream>

class Point_c
{
  public:
    // Default ctor (cartesian coordinates)
    Point_c (float arg1 = 0.0, float arg2 = 0.0) : x(arg1), y(arg2)
    {
      std::cout << "Default ctor called" << std::endl;
    }

  private:
    // Cartesian coordinates
    float x, y;

    // Polar coordinates
    float r, theta;
};

int main(int argc, char **argv)
{
  return 0;
}