/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  How to handle a constructor that fails ?
*/

#include <iostream>
#include <exception>

class ConstructorException : public std::exception
{
   public:
    /*
      This is a virtual method os the std::exception class that we are
      overwriting in our custom exception class

      The throw() at the end of the function declaration is called exception
      specification. It's purpose is to specify what kind of exception can come
      out of this method. In this case, throw() says that this method will throw
      nothing (this method does not throw any exception)
    */
    virtual const char *what() const throw()
    {
        return "A constructor exception happened";
    }
} ConstructorExc; /* This line creates a single instance of the ConstructorException class named
                  ConstructorExc */

class Foo
{
   public:
    Foo()
    {
        std::cout << "Foo default constructor will throw exception" << std::endl;
        throw(ConstructorExc);
    }
};

int main(int argc, char **argv)
{
    try
    {
        Foo obj1;
    }
    /* This handler catches an exception by reference, meaning that this also catches classes
     * derived from std::exception */
    catch (ConstructorException &err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}