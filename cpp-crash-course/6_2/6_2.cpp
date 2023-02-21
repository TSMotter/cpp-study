/*
  Course available @ https://github.com/rougier/CPP-Crash-Course

  Write a foo class with some attributes and write functions for writing to file
  and reading from file.
*/

#include <iostream>
#include <fstream>

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
    Foo(const char* file_name) : filename(file_name)
    {
        std::cout << "Default ctor called" << std::endl;
        close();
    }

    ~Foo()
    {
        std::cout << "Default dtor called" << std::endl;
        close();
    }

    void write(const char* s)
    {
        std::cout << "Writing: " << s << std::endl;
        File.open(filename, std::ofstream::out);
        File << s;
        close();
    }

    void read_print(void)
    {
        std::cout << "Reading: ";
        File.open(filename, std::ofstream::in);
        while (true)
        {
            if (File.eof())
            {
                std::cout << std::endl;
                break;
            }
            File >> _pchar;
            std::cout << _pchar << " ";
        }
        close();
    }

    void read(void)
    {
        File.open(filename, std::ofstream::in);
        std::string temp;
        while (true)
        {
            if (File.eof())
            {
                std::cout << std::endl;
                break;
            }
            File >> temp;
            _pchar.append(temp);
            _pchar.append(" ");
        }
        close();
    }

    friend std::ostream& operator<<(std::ostream& output, Foo& obj)
    {
        return (output << obj._pchar);
    }

   private:
    void open(void)
    {
        File.open(filename, std::ios::app);
        close();
    }

    void close(void)
    {
        if (File.is_open())
        {
            File.close();
        }
    }

    std::string  _pchar;
    const char*  filename;
    std::fstream File;
};

int main(int argc, char** argv)
{
    Foo obj1(FILE_NAME);

    obj1.write("Content written for test");

    // Method 1 for reading and printing
    // obj1.read_print();

    // Method 2 for reading (with insertion operator overloading)
    obj1.read();
    std::cout << "Reading: " << obj1 << std::endl;

    return 0;
}
