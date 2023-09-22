#include <iostream>
#include <memory>

class Base
{
   public:
    Base()
    {
        std::cout << "Default ctor BASE\n";
    }
    virtual ~Base()
    {
        std::cout << "Virtual dtor BASE\n";
    }
    virtual void virtual_method()
    {
        std::cout << "Base class virtual_method\n";
    }
    virtual void virtual_method_final() final
    {
        std::cout << "Base class virtual_method_final\n";
    }
    void non_virtual_method()
    {
        std::cout << "Base class non_virtual_method\n";
    }
};

class Derived : public Base
{
   public:
    Derived()
    {
        std::cout << "Default ctor Derived\n";
    }
    ~Derived()
    {
        std::cout << "Default dtor Derived\n";
    }
    /* In this case the "final" keyword is being used to make this the final version of this method,
     that is: it prevent further overriding of the method in any other point of the inheritance
     chain */
    virtual void virtual_method() override final
    {
        std::cout << "Derived class virtual_method\n";
    }
    // THIS WOULD BE A COMPILATION ERROR BECAUSE OF KEYWORD "final"
    /*
    virtual void virtual_method_final() override
    {
        std::cout << "Derived class virtual_method_final\n";
    }
    */
    void non_virtual_method()
    {
        std::cout << "Derived class non_virtual_method\n";
    }
};

class Dederived : public Derived
{
   public:
    Dederived()
    {
        std::cout << "Default ctor Dederived\n";
    }
    ~Dederived()
    {
        std::cout << "Default dtor Dederived\n";
    }

    // THIS WOULD BE A COMPILATION ERROR BECAUSE OF KEYWORD "final"
    /*
    virtual void virtual_method() override
    {
        std::cout << "Dederived class virtual_method\n";
    }
    */
};

class Eunuch final
{
};

// THIS WOULD BE A COMPILATION ERROR BECAUSE OF KEYWORD "final"
/*
class Child : Eunuch
{
};
*/

int main(int argc, char* argv[])
{
    std::unique_ptr<Base> obj = std::make_unique<Derived>();
    obj->virtual_method();
    obj->non_virtual_method();
}