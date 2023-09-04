#include <iostream>

template <typename T>
bool getParity(T num) {
    bool parity = false;
    while (num) {
        parity = !parity;
        num = num & (num - 1);
    }
    return parity;
}

int main() {
    int signedNum = -7;
    unsigned int unsignedNum = 7;

    std::cout << "Parity of signed integer " << signedNum << " is "
              << (getParity(signedNum) ? "odd" : "even") << std::endl;

    std::cout << "Parity of unsigned integer " << unsignedNum << " is "
              << (getParity(unsignedNum) ? "odd" : "even") << std::endl;

    return 0;
}