#include <iostream>

class Solution
{
public:
    int bitParity(int x)
    {
        int counter = 0;

        for (int bitshiftedCopy = x; bitshiftedCopy > 0 || bitshiftedCopy < -1; bitshiftedCopy = bitshiftedCopy >> 1) {
            counter += bitshiftedCopy & 1;
        }

        return counter & 1;
    }
};

int main()
{
    Solution s;

    std::cout << s.bitParity(INT32_MAX) << '\n';
}