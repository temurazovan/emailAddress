#include <iostream>

struct Email
{
    std::string firstPart;
    std::string secondPart;
}


int main() {
    std::string emailAddress;
    std::cout << "Enter your email address: ";
    std::cin >> emailAddress;
    std::string firstPartOfTheAddress;
    std::string secondPartOfTheAddress;


    bool isAtSignFound = false;
    for (char symbol: emailAddress) {
        if (symbol == '@') {
            isAtSignFound = true;
        }
        if (isAtSignFound == true) {
            secondPartOfTheAddress += symbol;
        }else{
            firstPartOfTheAddress += symbol;
        }
    }
    std::cout << firstPartOfTheAddress << std::endl;
    std::cout << secondPartOfTheAddress;
}
