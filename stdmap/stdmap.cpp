#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

enum class canmode
{
    tel,
    ser
};

std::map<int, std::string> map_k_int_v_str{{static_cast<int>(canmode::tel), "tel"},
                                           {static_cast<int>(canmode::ser), "ser"}};
std::map<std::string, int> map_k_str_v_int{{"tel", static_cast<int>(canmode::tel)},
                                           {"ser", static_cast<int>(canmode::ser)}};


int main(int argc, char **argv)
{
    canmode m_curr;

    int foo = map_k_str_v_int["invalidkey"];
    std::cout << "Testing map [1]: " << map_k_int_v_str[foo] << std::endl;


    auto it = map_k_str_v_int.find("invalid");
    if (it != map_k_str_v_int.end())
    {
        std::cout << "Testing map [2]: " << it->second << std::endl;
    }
    else
    {
        std::cout << "[FAIL] it == map_k_str_v_int.end()" << std::endl;
    }

    auto it2 = map_k_int_v_str.find(3);
    if (it2 != map_k_int_v_str.end())
    {
        std::cout << "Testing map [3]: " << it2->second << std::endl;
    }
    else
    {
        std::cout << "[FAIL] it2 == map_k_int_v_str.end()" << std::endl;
    }

    return 0;
}