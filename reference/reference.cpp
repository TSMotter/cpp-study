#include <iostream>
#include <assert.h>

void increment(int& val)
{
    val++;
}

int main(int argc, char** argv)
{
    int  a   = 5;
    int* ptr = &a;
    int& ref = a;

    std::cout << a << std::endl;

    ref = 2;
    std::cout << a << std::endl;

    increment(ref);
    std::cout << a << std::endl;

    return 0;
}