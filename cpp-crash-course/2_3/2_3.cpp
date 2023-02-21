/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a function that swap two integers, then two pointers.
*/

#include <iostream>
#include <stdio.h>

// Exploring the concept of overloading
// swap 2 integers
void swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1    = *var2;
    *var2    = temp;
}

// swap 2 pointers
void swap(int **var1, int **var2)
{
    int *temp = *var1;
    *var1     = *var2;
    *var2     = temp;
}

int main(int argc, char **argv)
{
    int  foo = 12, bar = 45;
    int *pfoo = &foo, *pbar = &bar;

    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    std::cout << "Swapping integers..." << std::endl;

    swap(&foo, &bar);

    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    std::cout << "Swapping pointers..." << std::endl;

    swap(&pfoo, &pbar);

    printf("foo = %d @ %p // bar = %d @ %p\n", foo, (void *) pfoo, bar, (void *) pbar);

    return 0;
}