// Course available @ https://github.com/rougier/CPP-Crash-Course

#include <iostream>
#include <cmath>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

/*
  METHOD == 1 -> NAMED CONSTRUCTORS
  METHOD == 2 -> SUB CLASSES AND OVERLOADING
*/
#define METHOD 1

#if (METHOD == 1)

/* 
  Thechnique called "Named Constructor Idiom":
    - Declare any constructorsyou need on the private or protected
    section of the class definition;
    - Provide public static methods that return an object, called
    Named Constructors, which will internally call the private constructor,
    but with an additional abstraction layer;
*/
class Point
{
  public:
    /*  
      These static methods are the so-called "named constructors". 
      They will act as 2 constructors options for this class, with parameters,
      but different names that better tell what they do.
      They need to be static members so that users can use the method without
      the need of declaring an object of this class.
    */
    // Named constructor for rectangular coordinates
    static Point rectangular(float x, float y)
    {
      return Point(x, y);
    }

    // Named constructor for polar coordinates
    static Point polar(float radius, float angle)
    {
      return Point(radius * std::cos(angle), radius * std::sin(angle));
    }

    float getMod()
    {
      return (sqrt((x_*x_) + (y_*y_)));
    }


  private:
    /* 
      Default ctor declared as a private member so that no user 
      of the class can access it directly. 
    */
    Point(float x, float y) : x_(x), y_(y)
    {
      std::cout << "Default ctor called" << std::endl;
    }

    float x_, y_;
};

int main(int argc, char **argv)
{
  // Obviously rectangular
  Point p1 = Point::rectangular(1, 1);

  // Obviously polar
  Point p2 = Point::polar(1.414213562373095, 0.785398163397448);

  std::cout << "p1 mod: " << p1.getMod() << std::endl;
  std::cout << "p2 mod: " << p2.getMod() << std::endl;

  return 0;
}

#elif (METHOD == 2)


//  Define 2 subclasses, one for each different type I want to be able to construct
class PolarPoint
{
  public:
    // Default ctor
    PolarPoint(float radius, float angle) : x_(radius*std::cos(angle)), y_(radius*std::sin(angle))
    {
    }
  
    float x_, y_;
};

class CartPoint
{
  public:
    // Default ctor
    CartPoint(float x, float y ) : x_(x), y_(y)
    {
    }
  
    float x_, y_;
};


//  Define 1 principal class with 2 constructors that refer to the sub classes
class Point
{
  public:
    // Constructor 1 takes a reference to a cartesian coord. as parameter
    Point(const CartPoint & obj) : x_(obj.x_), y_(obj.y_)
    {
      std::cout << "Default CartPoint ctor called" << std::endl;
    }

    // Constructor 2 takes a reference to a polar coord. as parameter
    Point(const PolarPoint & obj) : x_(obj.x_), y_(obj.y_)
    {
      std::cout << "Default PolarPoint ctor called" << std::endl;
    }

    float getMod()
    {
      return (sqrt((x_*x_) + (y_*y_)));
    }

  private:
    float x_, y_;
};

int main(int argc, char **argv)
{
  // Obviously rectangular
  Point p1(CartPoint(1, 1));

  // Obviously polar
  Point p2(PolarPoint(1.414213562373095, 0.785398163397448));

  std::cout << "p1 mod: " << p1.getMod() << std::endl;
  std::cout << "p2 mod: " << p2.getMod() << std::endl;

}

#endif

#pragma GCC diagnostic pop
