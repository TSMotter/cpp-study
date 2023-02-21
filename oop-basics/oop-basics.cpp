#include <iostream>

// Base class with encapsulated data and methods
class Shape
{
   public:
    int width, height;
    // Constructor
    Shape(int w, int h) : width(w), height(h)
    {
    }

    // Virtual destructor
    virtual ~Shape()
    {
    }

    // Abstract method for calculating the area of the shape
    virtual int area() = 0;

    // Method for printing the dimensions of the shape
    void printDimensions()
    {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

// Derived class that inherits from the Shape class
class Rectangle : public Shape
{
   public:
    // Constructor that calls the base class constructor
    Rectangle(int w, int h) : Shape(w, h)
    {
    }

    // Overrides the area method inherited from the Shape class
    int area()
    {
        return width * height;
    }
};

// Derived class that also inherits from the Shape class
class Triangle : public Shape
{
   public:
    // Constructor that calls the base class constructor
    Triangle(int w, int h) : Shape(w, h)
    {
    }

    // Overrides the area method inherited from the Shape class
    int area()
    {
        return (width * height) / 2;
    }
};

int main()
{
    // Create a Rectangle object using polymorphism
    Shape *shape1 = new Rectangle(10, 5);
    std::cout << "Rectangle area: " << shape1->area() << std::endl;
    shape1->printDimensions();

    // Create a Triangle object using polymorphism
    Shape *shape2 = new Triangle(10, 5);
    std::cout << "Triangle area: " << shape2->area() << std::endl;
    shape2->printDimensions();

    // Deallocate the objects
    delete shape1;
    delete shape2;

    return 0;
}
