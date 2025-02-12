#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Stores max num for each digit sum
        int maxSum = -1;

        for (int num : nums) {
            int digitSum = getDigitSum(num);

            if (digitSumMap.find(digitSum) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[digitSum] + num);
            }
            
            digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
        }

        return maxSum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
