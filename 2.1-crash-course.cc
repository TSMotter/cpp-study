// Course available @ https://github.com/rougier/CPP-Crash-Course

#include <iostream>

int main(int argc, char **argv)
{
  // char
  char Z = 0x5A;
  std::cout<<"char: " << Z << std::endl;

  // const char 
  const char W = 0x57;
  std::cout<<"const char:  " << W << std::endl;

  // pointer to char
  char *A = &Z;
  std::cout<<"pointer to char: " << A << std::endl;

  // constant pointer to a char
  char * const B = A;
  std::cout<<"constant pointer to a char: " << B << std::endl;

  // pointer to a constant char
  const char * C = &W;
  std::cout<<"pointer to a constant char: " << C << std::endl;

  // constant pointer to a constant char
  const char * const D = A;
  std::cout<<"constant pointer to a constant char: " << D << std::endl;

  // reference to a char
  char &E = Z;
  std::cout<<"reference to a char: " << E << std::endl;

  // reference to a constant char
  const char &F = W;
  std::cout<<"reference to a constant char: " << F << std::endl;

  return 0;
}