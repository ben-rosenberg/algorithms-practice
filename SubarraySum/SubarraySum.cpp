#include <vector>
#include <iostream>

/**
 * @brief Solution to the "Subarray Sum" problem from GeeksForGeeks.com 
 */
class Solution
{
public:
    /**
     * @brief Solution to the subArraySum problem
     * 
     * Given an array of integers arr with a length of n, find the first
     * continuous series of elements that sum to s. The result should be a
     * vector of ints containing the 1-indexed positions of the first and last
     * elements in the series of numbers that sum to s, or -1 if no series of
     * such elements is found.
     * 
     * @param arr An array of unsorted numbers.
     * @param n The length of the array.
     * @param s The desired subarray sum value.
     * @return std::vector<int> The 1-indexed indices of the first and last elements
     */
    std::vector<int> SubArraySum(int arr[], int n, long long s)
    {
        int subArrayStartIdx = 0;
        int runningSum = 0;

        for (int i = 0; i < n; ++i) {
            runningSum += arr[i];

            while (runningSum > s) {
                runningSum -= arr[subArrayStartIdx];
                subArrayStartIdx++;
            }

            if (runningSum == s) {
                return std::vector<int>{ subArrayStartIdx + 1, i + 1 };
            }
        }

        return std::vector<int>{ -1 };
    }
};


int main()
{
    Solution s;

    // Expected solution: { 2, 4 }
    int nums1[5] = { 1, 2, 3, 7, 5 };
    long long s1 = 12;

    // Expected solution: { 3, 5 }
    int nums2[7] = { 4, 13, 2, 6, 12, 1, 7 };
    long long s2 = 20;

    std::vector<int> result1 = s.SubArraySum(nums1, 5, s1);
    std::vector<int> result2 = s.SubArraySum(nums2, 7, s2);

    std::cout << "Result 1: " << result1[0] << ", " << result1[1] << '\n';
    std::cout << "Result 2: " << result2[0] << ", " << result2[1] << '\n';
}