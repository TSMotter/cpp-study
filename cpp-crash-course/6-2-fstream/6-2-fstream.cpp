/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a foo class with some attributes and write functions for writing to file
  and reading from file.
*/

#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "my_file.txt"

/*
  This operator (<<) applied to an output stream is known as insertion operator.
  This operator (>>) applied to an input stream is known as extraction operator

  Stream classes:
  ofstream (write on file), ifstream (read from file), fstream (both)
  These classes are derived directly or indirectly from the classes istream and
  ostream. cin is an object of class istream and cout is an object of class
  ostream
*/
class Foo
{
   public:
    Foo(const char* filename) : m_filename(filename)
    {
        std::cout << "Foo default constructor" << std::endl;
        open();
    }

    ~Foo()
    {
        std::cout << "Foo default destructor" << std::endl;
        close();
    }

    void write(const char* s)
    {
        m_fstream << s;
        m_fstream.flush();
    }


    void read(void)
    {
        m_fstream.seekg(0, std::ios::beg);
        m_content.clear();

        std::string line;
        while (std::getline(m_fstream, line))
        {
            m_content += line;
            m_content += "\n";
        }

        m_fstream.clear();
    }

    friend std::ostream& operator<<(std::ostream& output, Foo const& obj)
    {
        return output << obj.m_content;
    }

   private:
    void open(void)
    {
        m_fstream.open(m_filename, std::fstream::in | std::fstream::out | std::fstream::app);
    }

    void close(void)
    {
        if (m_fstream.is_open())
        {
            m_fstream.close();
        }
    }

    std::string  m_content;
    const char*  m_filename;
    std::fstream m_fstream;
};

int main(int argc, char** argv)
{
    Foo foo{FILE_NAME};

    foo.write("Content written for test\n");

    foo.read();
    std::cout << "Reading:\n" << foo << std::endl;

    std::cout << "-----------------------" << std::endl;

    foo.write("And here is some extra content...\n");

    foo.read();
    std::cout << "Reading:\n" << foo << std::endl;

    return 0;
}
