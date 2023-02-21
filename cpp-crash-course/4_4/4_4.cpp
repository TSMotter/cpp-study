/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Singleton class such that only one object of this class can be
  created.
*/

#include <iostream>

class Singleton
{
   public:
    static Singleton *getInstance()
    {
        static Singleton INSTANCE;
        return &INSTANCE;
    }

   private:
    Singleton()
    {
        std::cout << "Default ctor called" << std::endl;
    }
};

int main(int argc, char **argv)
{
    Singleton *obj1 = Singleton::getInstance();
    Singleton *obj2 = Singleton::getInstance();

    if (obj1 == obj2)
    {
        std::cout << "The pointers are equal" << std::endl;
    }

    return 0;
}