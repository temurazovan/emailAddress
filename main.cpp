#include <iostream>

struct Email {
    std::string firstPart;
    std::string secondPart;
    std::string originalEmail;
};

Email parseEmail(std::string email) {
    Email result;
    result.originalEmail = email;
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
            && symbol != '~' && symbol != '.') {
            return false;
        }
    }

    return true;
}

bool checkEmail(Email parsedEmail) {
    int k = 0;
    for (char symbols: parsedEmail.originalEmail) {
        if (symbols == '@') {
            k++;
            if (k != 1) {
                return false;
            }
        }
    }


    if ((parsedEmail.firstPart.empty() || parsedEmail.firstPart.length() > 64)
        || !checkSymbols(parsedEmail.firstPart)) {
        return false;
    }

    char lastSymbol = parsedEmail.secondPart[parsedEmail.secondPart.length() - 1];;

    if (parsedEmail.secondPart.empty() || !checkSymbols(parsedEmail.secondPart)
        || lastSymbol == '-') {
        return false;
    }

    return true;
}


int main() {
    std::string emailAddress;
    std::cout << "Enter your email address: ";
    getline(std::cin, emailAddress);
    Email parsedEmail = parseEmail(emailAddress);

    if (checkEmail(parsedEmail)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

}
