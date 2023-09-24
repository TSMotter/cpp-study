/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Foo class and provide it with an input method.
*/

#include <iostream>
#include <cmath>

class Point
{
   public:
    // Default ctor
    Point(void) : x_(0.0), y_(0.0){};

    // "Named constructor"
    static Point cartesian(const float x, const float y)
    {
        return Point(x, y);
    }

    // "Named constructor"
    static Point polar(const float rho, const float theta)
    {
        return Point(rho * std::cos(theta), rho * std::sin(theta));
    }

    // Operator ">>" overloading
    friend std::istream &operator>>(std::istream &input, Point &that)
    {
        return input >> that.x_ >> that.y_;
    }

    // Operator "<<" overloading
    friend std::ostream &operator<<(std::ostream &output, Point &that)
    {
        return output << "(" << that.x_ << ", " << that.y_ << ")";
    }

    float getMod()
    {
        return (sqrt((x_ * x_) + (y_ * y_)));
    }

   private:
    Point(const float x, const float y) : x_(x), y_(y){};
    float x_;
    float y_;
};


int main(int argc, char **argv)
{
    Point p;
    std::cout << "Enter a new point x y: ";
    std::cin >> p;
    std::cout << "p  = " << p << std::endl;

    std::cout << "point mod: " << p.getMod() << std::endl;

    return 0;
}