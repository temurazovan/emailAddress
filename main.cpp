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

bool checkEmail(Email parsedEmail) {
    if (parsedEmail.firstPart.empty() || parsedEmail.firstPart.length() > 64) {
        return false;
    }

    for (int i = 0; i < parsedEmail.firstPart.length(); i++) {
        if (parsedEmail.firstPart[i] == '.' && parsedEmail.firstPart[i + 1] == '.') {
            return false;
        }
    }

    for (char symbol: parsedEmail.firstPart) {
        if (!isalnum(symbol) && symbol != '!' && symbol != '#' && symbol != '$' && symbol != '%' && symbol != '&' &&
            symbol != '\''
            && symbol != '*' && symbol != '+' && symbol != '-' && symbol != '/' && symbol != '=' && symbol != '?'
            && symbol != '^' && symbol != '_' && symbol != '`' && symbol != '{' && symbol != '|' && symbol != '}'
            && symbol != '~' && symbol != '.') {
            return false;
        }
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
