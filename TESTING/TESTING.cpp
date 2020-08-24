#include <string>
#include <iostream>

int main()
{

    std::string str_smol = "smol";
    std::string str_bigg = "_____________big________________________________________";

    std::cout << "The two strings are\n"
        << str_smol << " \n"
        << str_bigg << " \n";

    std::cin.ignore();
    return 0;

}