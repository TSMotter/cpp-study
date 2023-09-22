/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a function that swap two integers, then two pointers.
*/

#include <iostream>
#include <stdio.h>

class Meme
{
   public:
    Meme(char c = 0) : m_var(c)
    {
        std::cout << "Meme default constructor" << std::endl;
    }

    Meme(const Meme &other)
    {
        m_var = other.m_var;
        std::cout << "Meme copy constructor" << std::endl;
    }

    // Meme(Meme &&other)
    //{
    //     m_var = other.m_var;
    //     // other.m_var = nullptr;
    //     std::cout << "Meme move constructor" << std::endl;
    // }

    friend std::ostream &operator<<(std::ostream &output, Meme &obj)
    {
        return output << obj.m_var;
    }

   private:
    char m_var;
};

// Exploring the concept of overloading
// swap 2 values using raw pointers
void swap(int *var1, int *var2)
{
    std::cout << "---- void swap(int *var1, int *var2) ----" << std::endl;
    int temp = *var1;
    *var1    = *var2;
    *var2    = temp;
}

// swap 2 pointers
void swap(int **var1, int **var2)
{
    std::cout << "---- void swap(int **var1, int **var2) ----" << std::endl;
    int *temp = *var1;
    *var1     = *var2;
    *var2     = temp;
}

// swap 2 values using references
void swap(int &var1, int &var2)
{
    std::cout << "---- void swap(int &var1, int &var2) ----" << std::endl;
    int temp = var1;
    var1     = var2;
    var2     = temp;
}

template <class T>
void generic_swap(T *var1, T *var2)
{
    std::cout << "---- void generic_swap(T *var1, T *var2) ----" << std::endl;
    T temp = *var1;  // This evokes the copy constructor
    *var1  = *var2;
    *var2  = temp;
}

int main(int argc, char **argv)
{
    int  foo  = 12;
    int *pfoo = &foo;
    int &rfoo = foo;

    int  bar  = 45;
    int *pbar = &bar;
    int &rbar = bar;

    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    std::cout << "Swapping value using raw pointers..." << std::endl;
    swap(&foo, &bar);  // alternative: swap(pfoo, pbar);
    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    std::cout << "Swapping pointers..." << std::endl;
    swap(&pfoo, &pbar);
    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    std::cout << "Swapping value using references..." << std::endl;
    swap(rfoo, rbar);
    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    Meme m1{88};
    Meme m2{89};
    std::cout << "m1: " << m1 << " // m2: " << m2 << std::endl;
    generic_swap<Meme>(&m1, &m2);
    std::cout << "m1: " << m1 << " // m2: " << m2 << std::endl;

    return 0;
}