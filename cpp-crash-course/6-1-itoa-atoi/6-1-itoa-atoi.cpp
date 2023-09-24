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
    ItoA(int value) : m_i(value)
    {
        std::cout << "ItoA constructor" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& output, ItoA const& that)
    {
        return output << that.m_a;
    }
    friend std::istream& operator>>(std::istream& input, ItoA& foo)
    {
        return input >> foo.m_i;
    }

    int _itoa()
    {
        return sprintf(m_a, "%d", m_i);
    }

   private:
    int  m_i;
    char m_a[20];
};

class AtoI
{
   public:
    AtoI()
    {
        std::cout << "AtoI constructor" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& output, AtoI const& that)
    {
        return output << that.m_i;
    }
    friend std::istream& operator>>(std::istream& input, AtoI& foo)
    {
        return input >> foo.m_a;
    }

    void _atoi()
    {
        m_i = atoi(m_a);
    }

   private:
    int  m_i;
    char m_a[20];
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