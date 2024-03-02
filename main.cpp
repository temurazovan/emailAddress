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


bool allowedSymbolsForSecondPart(std::string string) {
    for (char symbol: string) {
        if (!isalnum(symbol) && symbol != '.' && symbol != '-') {
            return false;
        }
    }
    return true;
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


    if (
            parsedEmail.secondPart.empty()
            || parsedEmail.secondPart.length() > 63
            || !allowedSymbolsForSecondPart(parsedEmail.secondPart)
            || lastSymbol == '-'
            ) {
        return false;
    }

    return true;
}

//void test() {
//    std::string emails[] = {
//            "simple@example.com",
//            "very.common@example.com",
//            "disposable.style.email.with+symbol@example.com",
//            "other.email-with-hyphen@example.com",
//            "fully-qualified-domain@example.com",
//            "user.name+tag+sorting@example.com",
//            "x@example.com",
//            "example-indeed@strange-example.com",
//            "admin@mailserver",
//            "example@s.example",
//            "mailhost!username@example.org",
//            "user%example.com@example.org",
//            "John..Doe@example.com",
//            "Abc.example.com",
//            "A@b@c@example.com",
//            "a\"b(c)d,e:f;g<h>i[j\\k]l@example.com",
//            "1234567890123456789012345678901234567890123456789012345678901234+x@example.com",
//            "i_like_underscore@but_its_not_allow_in _this_part.example.com",
//    };
//
//    for (auto email: emails) {
//        Email parsedEmail = parseEmail(email);
//        std::cout << email << " - " << (checkEmail(parsedEmail) ? "yes" : "no" ) << std::endl;
//    }
//}

int main() {
    // test(); return 0;

    std::string emailAddress;
    std::cout << "Enter your email address: ";
    getline(std::cin, emailAddress);
    Email parsedEmail = parseEmail(emailAddress);

    if (checkEmail(parsedEmail)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    return 0;
}
