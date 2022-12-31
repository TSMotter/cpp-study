/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a const correct division function.
*/

#include <iostream>
#include <cassert>

float my_div(const int num, const int den)
{
  assert(den != 0);
  return (num / den);
}

int main(int argc, char **argv)
{
  my_div(2, 1);

  return 0;
}