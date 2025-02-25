class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1, sum = 0, result = 0;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) { // Even sum
                result = (result + oddCount) % MOD;
                evenCount++;
            } else { // Odd sum
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }
        return result;
    }
};