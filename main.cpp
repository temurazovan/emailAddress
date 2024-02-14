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

bool checkSymbols(std::string partOfTheAddress) {
    for (int i = 0; i < partOfTheAddress.length(); i++) {
        if (partOfTheAddress[0] == '.' || (partOfTheAddress[i] == '.' && i + 1 <= partOfTheAddress.length()
                                           && partOfTheAddress[i + 1] == '.')) {
            return false;
        }
        char symbol = partOfTheAddress[i];
        if (!isalnum(symbol) && symbol != '!' && symbol != '#' && symbol != '$' && symbol != '%' && symbol != '&' &&
            symbol != '\''
            && symbol != '*' && symbol != '+' && symbol != '-' && symbol != '/' && symbol != '=' && symbol != '?'
            && symbol != '^' && symbol != '_' && symbol != '`' && symbol != '{' && symbol != '|' && symbol != '}'
            && symbol != '~' && symbol != '.' && symbol == ' ') {
            return false;
        }
    }

    return true;
}

bool checkEmail(Email parsedEmail) {
    if ((parsedEmail.firstPart.empty() || parsedEmail.firstPart.length() <= 64)
        && !checkSymbols(parsedEmail.firstPart)) {
        return false;
    }

    if (parsedEmail.secondPart.empty() && !checkSymbols(parsedEmail.secondPart)) {
        return false;
    }

    return true;
}


int main() {
    std::string emailAddress;
    std::cout << "Enter your email address: ";
    std::cin >> emailAddress;
    Email parsedEmail = parseEmail(emailAddress);

    if (checkEmail(parsedEmail)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

}
