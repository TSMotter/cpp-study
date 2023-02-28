/* Reference: https://herbsutter.com/2013/05/09/gotw-1-solution/ */

#include <iostream>

/* Checking the differences between:
    default initialization
    direct initialization
    copy initialization
    list initialization */

class Bar
{
   public:
    Bar()
    {
        std::cout << "Bar default constructor" << std::endl;
    }

    Bar(char ch) : m_char(ch)
    {
        std::cout << "Bar constructor with char param" << std::endl;
    }

   private:
    char m_char;
};

class Meme
{
   public:
    Meme()
    {
        std::cout << "Meme default constructor" << std::endl;
    }

    Meme(std::initializer_list<int> ls) : m_list(ls)
    {
        std::cout << "Meme constructor with std::initializer_list<int> param" << std::endl;
    }

   private:
    std::initializer_list<int> m_list;
};

class Foo
{
   public:
    Foo()
    {
        std::cout << "Foo default constructor" << std::endl;
    }

    Foo(int val) : m_val(val)
    {
        std::cout << "Foo constructor with int param" << std::endl;
    }

    Foo(Bar b)
    {
        std::cout << "Foo constructor with Bar obj as param" << std::endl;
    }

    Foo(std::initializer_list<int> ls)
    {
        std::cout << "Foo constructor with std::initializer_list<int> param" << std::endl;
    }

   private:
    int m_val;
};

/*
General information:
- The syntax {x} creates an std::initializer_list
*/

int main(int argc, char* argv[])
{
    // ---------------------------------------------------------------------------------------------

    /*
    warning: empty parentheses were disambiguated as a function
    declaration [-Wvexing-parse]

    This is a pre-modern C++ pitfall: At first glance, it may look like just another variable
    declaration calling a default construconstructor Foo::Foo(); in reality, thanks to a grammar
    ambiguity, it’s a function declaration for a function named "foo", that takes no parameters and
    returns a "Foo" object by value.

    "if it can be a function declaration, it is."
    Foo foo();
    Foo foo(Bar());
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is a default initialization.
    Note that "obj" is not initialized and contains garbage values if Foo happens to be a built-in
    type like "int", or a simple “int-like” class type with what’s called a “trivial” default
    construconstructor (a type that relies on the compiler-generated default construconstructor),
    has no virtual functions or virtual base classes or data member initializers, and all its bases
    and members satisfy the same restrictions
    Foo obj;
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is a direct initialization.
    Assuming "a" is not the name of a type (ie: int)
    int a = 2;
    Foo a1(a);
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is a list initialization (recomended)
    This method always initializes the variable, and is never ambiguous with a function declaration.

    Even in the case of "Meme" class, that has a constructor that accepts a std::initializer_list
    as parameter, when defining "b1", the default constructor is called, because {} is empty
    Foo  b{};
    Meme b1{};
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is once again a direct initialization.
    Because "Meme" class has a constructor that accepts a std::initializer_list as parameter and I'm
    passing a non empty std::initializer_list as parameter, that constructor is prefered
    int  c = 2;
    Meme c1{c};
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> The syntax with "{}" is also prefered over the "()" because it prevents narrowing
    // Compiles: but you toss away the .345
    int i1(12.345);
    // Error: would be lossy implicit narrowing
    int i2{12.345};
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is a copy initialization.
    Conceptually, the variable "d1" is initialized using Foo‘s move or copy constructor possibly
    after calling another function to convert the argument implicitly.

    Common Mistake: This is always initialization; it is never assignment, and so it never calls
    T::operator=(). Yes, there’s an “=” character in there, but don’t let that throw you —
    that’s just a syntax holdover from C, not an assignment operation.

    In this case, "d" is the same type of "d1", so:
    "Foo d1 = d;" is equivalent to "Foo d1(d);" In both cases, only 1 default constructor is called
    Foo d{};
    Foo d1 = d;
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is also a copy initialization.

    In this case, "e" is a different type of "e1", so:
    "Foo e1 = e;" is equivalent to "Foo e1(Foo(e));", which uses de constructor with an int param.

    It is possible that a move constructor gets used in this kind of situation.
    int e  = 8;
    Foo e1 = e;
    */

    // ---------------------------------------------------------------------------------------------

    /* ----> This is a copy list initialization.

    In this case, it'll behave the same as the cases above, the constructor that will end up being
    used depends on the type of "f". It it's a "Foo" object, just 1 default constructor is called.
    If it is an "int", then the std::initializer_list<int> constructor is called, since "Foo" has a
    specific constructor for that.
    */
    // Foo f{};
    int f  = 8;
    Foo f1 = {f};
}