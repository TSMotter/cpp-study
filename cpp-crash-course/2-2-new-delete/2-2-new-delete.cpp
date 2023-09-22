/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Create a two-dimensional array of integers (size is n x n), fill it with
  corresponding indices (a[i][j] = i*n+j), test it and finally, delete it.
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main(int argc, char **argv)
{
    size_t n;

    std::cout << "Please enter the matrix dimension: ";
    std::cin >> n;
    std::cout << "n chosen: " << n << std::endl;

    // Allocating bidimensional array
    int **a = new int *[n];
    for (size_t k = 0; k < n; ++k)
    {
        a[k] = new int[n];
    }

    // Filling the array
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            a[i][j] = (i * n + j);
            std::cout << "array[" << i << "," << j << "] = " << a[i][j] << std::endl;
        }
    }

    // Deallocating bidimensional array
    for (size_t k = 0; k < n; ++k)
    {
        delete[] a[k];
    }
    delete[] a;

    return 0;
}