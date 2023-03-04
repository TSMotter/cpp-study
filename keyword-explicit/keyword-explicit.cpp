#include <iostream>

class Complex
{
   private:
    double m_real;
    double m_imag;

   public:
    // Parameterized constructor
    Complex(double r = 0.0, double i = 0.0) : m_real(r), m_imag(i)
    {
    }

    bool operator==(Complex rhs)
    {
        return (m_real == rhs.m_real && m_imag == rhs.m_imag);
    }
};

class ComplexExpl
{
   private:
    double m_real;
    double m_imag;

   public:
    // Parameterized constructor
    explicit ComplexExpl(double r = 0.0, double i = 0.0) : m_real(r), m_imag(i)
    {
    }

    bool operator==(ComplexExpl rhs)
    {
        return (m_real == rhs.m_real && m_imag == rhs.m_imag);
    }
};

int main(int argc, char **argv)
{
    /* Since the constructor of "Complex" allows for the construction of an object with only 1
     * parameter (because it has 2 parameters but with default value), this comparison will lead to
     * an implicit construction of an object of type "Complex", (Complex foo(3.0)) */

    Complex com1(3.0, 0.0);
    if (com1 == 3.0)
    {
        std::cout << "Same" << std::endl;
    }
    else
    {
        std::cout << "Not Same" << std::endl;
    }

    /* To avoid this implicit construction, we should mark que constructor "explicit" */
    ComplexExpl com_expl(5.0, 0.0);
    // THIS IS A COMPILATION ERROR:
    // if (com_expl == 5.0)
    //{
    //    std::cout << "Same" << std::endl;
    //}
    // else
    //{
    //    std::cout << "Not Same" << std::endl;
    //}

    return 0;
}