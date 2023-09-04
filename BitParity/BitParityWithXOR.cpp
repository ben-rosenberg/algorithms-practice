#include <iostream>
#include <bitset>
#include <climits>

template <typename T>
bool getParity(T num) {
    std::bitset<sizeof(T) * CHAR_BIT> bits(num);
    bool parity = 0;
    for(size_t i = 0; i < bits.size(); ++i) {
        parity ^= bits[i];
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