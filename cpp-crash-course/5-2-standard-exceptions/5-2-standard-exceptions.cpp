/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a program that raise 3 of the standard exceptions.
*/

#include <iostream>
#include <exception>
#include <typeinfo>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

class Foo
{
    virtual void method(void)
    {
    }
};

class Bar : public Foo
{
};

int main(int argc, char **argv)
{
    try
    {
        throw std::bad_alloc();

        // int *array = new int[-1];
        // int  i     = 0;
        // i          = array[0];
    }
    catch (std::exception &err)
    {
        std::cout << "A standard exception happened: " << err.what() << std::endl;
    }

    /*
      dynamic_cast<Type*>(ptr)
      This will take pointer ptr and cast it to a pointer of type Type* in
      runtime It's useful in polymorphic classes This can go 1 of 2 ways: 1)
      base class to derived class 2) derived class to base class
    */
    try
    {
        // throw std::bad_cast();

        Foo  f;
        Bar &b = dynamic_cast<Bar &>(f);
    }
    catch (std::exception &err)
    {
        std::cout << "A standard exception happened: " << err.what() << std::endl;
    }

    try
    {
        throw std::bad_typeid();
    }
    catch (std::exception &err)
    {
        std::cout << "A standard exception happened: " << err.what() << std::endl;
    }

    return 0;
}

#pragma GCC diagnostic pop