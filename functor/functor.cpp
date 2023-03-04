#include <iostream>
#include <assert.h>

/* This is a functor - a class which defines the operator() which lets you create objects which
 * "look like" a function. Similar somehow to lambdas

 Advantages:
 - When you instantiate a functor object, because it is an object, it con keep a context within
 itself (see fibon example below)
 - If you instantiate different functor objects with different construction parameters, it'll behave
 different (easily customizable)

*/
struct add_x
{
    add_x(int val) : x(val)
    {
    }  // Constructor
    int operator()(int y) const
    {
        return x + y;
    }

   private:
    int x;
};

/* This keeps context (state) between calls */
class fibon
{
   private:
    int m_prevprev;
    int m_prev;

   public:
    fibon() : m_prevprev(0), m_prev(1)
    {
    }
    int operator()()
    {
        int res    = m_prevprev + m_prev;
        m_prevprev = m_prev;
        m_prev     = res;
        return res;
    }
};

int main(int argc, char **argv)
{
    add_x add42{42};
    int   i = add42(8);
    assert(i == 50);

    fibon f = fibon{};
    for (uint k = 0; k < 8; k++)
    {
        int i = f();
        std::cout << i << std::endl;
    }

    return 0;
}