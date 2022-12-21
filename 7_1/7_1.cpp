/*
  Course available @ https://github.com/rougier/CPP-Crash-Course
*/

#include <iostream>

template <class T>
void generic_swap(T *a, T *b)
{
  T temp = *a;
  *a     = *b;
  *b     = temp;
}

int main(int argc, char **argv)
{
  int A = 2, B = 3;
  generic_swap<int>(&A, &B);
  std::cout << "A: " << A << " B: " << B << std::endl;

  float C = 2.5, D = 3.5;
  generic_swap<float>(&C, &D);
  std::cout << "C: " << C << " D: " << D << std::endl;

  return 0;
}