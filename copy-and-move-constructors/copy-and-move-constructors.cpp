#include <iostream>

class MyClass
{
   public:
    int* data;

    // Default Constructor
    MyClass()
    {
        std::cout << "Default Constructor called" << std::endl;
    }

    // Copy Constructor
    MyClass(const MyClass& other)
    {
        data = other.data;
        std::cout << "Copy Constructor called" << std::endl;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept
    {
        data       = other.data;
        other.data = nullptr;
        std::cout << "Move Constructor called" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& output, MyClass const& that)
{
    return output << *that.data << std::endl;
}

int main()
{
    MyClass obj1{};  // Default constructor
    obj1.data = new int(42);
    std::cout << "This is obj1: " << obj1;

    MyClass obj2{obj1};  // Copy constructor
    std::cout << "This is obj1: " << obj1;
    std::cout << "This is obj2: " << obj2;

    MyClass obj3{std::move(obj2)};  // Invokes the move constructor;
    std::cout << "This is obj1: " << obj1;
    // std::cout << "This is obj2: " << obj2; // This would be a segfault because obj2 no longer
    // 'exists'
    std::cout << "This is obj3: " << obj3;

    delete obj3.data;  // Clean up the data

    return 0;
}
