#include <iostream>

struct Email {
    std::string firstPart;
    std::string secondPart;
};

Email parseEmail(std::string email) {
    Email result;
    bool isAtSignFound = false;

    for (char symbol: email) {
        if (symbol == '@') {
            isAtSignFound = true;
        }

        if (!isAtSignFound) {
            result.firstPart += symbol;
        } else {
            if (symbol != '@') {
                result.secondPart += symbol;
            }
        }
    }

    return result;
}


int main() {
    std::string emailAddress;
    std::cout << "Enter your email address: ";
    std::cin >> emailAddress;
    Email parsedEmail = parseEmail(emailAddress);

    std::cout << parsedEmail.firstPart << std::endl;
    std::cout << parsedEmail.secondPart << std::endl;
}
