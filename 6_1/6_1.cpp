/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write an itoa and an atoi function
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

class ItoA
{
 public:
  ItoA(int x) : _value(x)
  {
    std::cout << "IntToAscii ctor called" << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& output, ItoA const& that)
  {
    return output << that._string;
  }
  friend std::istream& operator>>(std::istream& input, ItoA& foo)
  {
    return input >> foo._value;
  }

  int _itoa()
  {
    return sprintf(_string, "%d", _value);
  }

 private:
  int  _value;
  char _string[20];
};

class AtoI
{
 public:
  AtoI()
  {
    std::cout << "AsciiToInt ctor called" << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& output, AtoI const& that)
  {
    return output << that._value;
  }
  friend std::istream& operator>>(std::istream& input, AtoI& foo)
  {
    return input >> foo._string;
  }

  void _atoi()
  {
    _value = atoi(_string);
  }

 private:
  int  _value;
  char _string[20];
};

int main(int argc, char** argv)
{
  ItoA obj1(0);
  std::cout << "Enter an integer number between -100 and +100: " << std::endl;
  std::cin >> obj1;
  obj1._itoa();
  std::cout << obj1 << std::endl;


  AtoI obj2;
  std::cout << "Enter an integer number between -100 and +100: " << std::endl;
  std::cin >> obj2;
  obj2._atoi();
  std::cout << obj2 << std::endl;

  return 0;
}