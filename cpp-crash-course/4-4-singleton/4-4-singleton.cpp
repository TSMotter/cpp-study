/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a Singleton class such that only one object of this class can be
  created.
*/


/*
The concept if a singleton is based on a shallow copy, that is, when there are 2 references to
the singleton, they must both point to the same area in memory (the single instane) and not to
different areas in memory (what would be the primitive of a deep copy)
*/

#include <iostream>
#include <cassert>

/* Singleton using pointer */
class Singletonp
{
   public:
    static Singletonp* Instance()
    {
        if (nullptr == inst)
        {
            inst = new Singletonp();
        }
        return inst;
    }

    ~Singletonp()
    {
        delete inst;
    }

    Singletonp(const Singletonp& other)
    {
        std::cout << "Singletonp copy constructor" << std::endl;
    }

    void var(char v)
    {
        m_var = v;
    }

    char var()
    {
        return m_var;
    }

   private:
    Singletonp()
    {
        std::cout << "Singletonp default private constructor" << std::endl;
    }

    /* Because this is a static member variable of the class, it is the same variable shared among
     * all instances of this class */
    static Singletonp* inst;

    char m_var;
};

/* Singleton using reference */
class Singletonr
{
   public:
    static Singletonr& Instance()
    {
        static Singletonr inst;
        return inst;
    }

    Singletonr(const Singletonr& other)
    {
        std::cout << "Singletonr copy constructor" << std::endl;
    }

    void var(char v)
    {
        m_var = v;
    }

    char var()
    {
        return m_var;
    }


   private:
    Singletonr()
    {
        std::cout << "Singletonr default private constructor" << std::endl;
    }

    char m_var;
};

/* This "syntax" is only valid because "inst" is a static member variable of the class */
Singletonp* Singletonp::inst = nullptr;


int main(int argc, char** argv)
{
    Singletonp* singp1 = Singletonp::Instance();
    singp1->var('F');
    std::cout << "singp1->var()=" << singp1->var() << std::endl;
    Singletonp* singp2 = Singletonp::Instance();
    std::cout << "singp2->var()=" << singp2->var() << std::endl;
    assert(singp1->var() == singp2->var());

    std::cout << "-----------------------" << std::endl;

    Singletonr& singr1 = Singletonr::Instance();
    singr1.var('G');
    std::cout << "singr1.var()=" << singr1.var() << std::endl;
    Singletonr& singr2 = Singletonr::Instance();
    std::cout << "singr2.var()=" << singr2.var() << std::endl;
    assert(singr1.var() == singr2.var());

    return 0;
}