#include <iostream>
#include <memory>

class Meme
{
   public:
    Meme()
    {
        std::cout << "Default constructor of Meme called" << std::endl;
    }
    ~Meme()
    {
        std::cout << "Default destructor of Meme called" << std::endl;
    }

    void echo()
    {
        std::cout << "Meme's 'echo' method called" << std::endl;
    }
};

void printer(const std::string &s)
{
    std::cout << s << std::endl;
}

int main(int argc, char **argv)
{
    printer("----Test unique_ptr----");
    // Create a scope to test unique_ptr
    {
        printer("1a");
        // Only available in C++ 14 onwards
        std::unique_ptr<Meme> foo = std::make_unique<Meme>();

        // This is a compilation error because the copy constructor and the assignment operator (=)
        // are deleted for this class:
        // std::unique_ptr<Meme> bar = foo;

        printer("2a");
    }
    printer("3a");
    printer("-----------------------");

    printer("----Test shared_ptr----");
    // Create a scope to test shared_ptr
    {
        printer("1b");
        std::shared_ptr<Meme> bar;
        {
            printer("2b");
            std::shared_ptr<Meme> foo = std::make_shared<Meme>();
            bar                       = foo;
            printer("3b");
        }
        printer("4b");
    }  // <-- Destructor will only get evoked here
    printer("5b");
    printer("----------------------");

    printer("----Test weak_ptr----");
    // Create a scope to test weak_ptr
    {
        printer("1c");
        std::weak_ptr<Meme> bar;
        {
            printer("2c");
            std::shared_ptr<Meme> foo = std::make_shared<Meme>();
            bar                       = foo;
            printer("3c");
        }  // <-- Destructor will only get evoked here (weak_ptr does not keep the object alive)
        printer("4c");
    }
    printer("5c");
    printer("---------------------");

    return 0;
}