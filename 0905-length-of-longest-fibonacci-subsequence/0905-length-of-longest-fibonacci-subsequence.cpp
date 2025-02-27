class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        unordered_map<int, int> dp;
        int maxLength = 0;

        // Store index of each element
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Iterate through pairs of elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int target = arr[i] - arr[j];
                if (target < arr[j] && index.find(target) != index.end()) {
                    int k = index[target];
                    int length = dp[k * n + j] + 1;
                    dp[j * n + i] = max(length, 3);
                    maxLength = max(maxLength, dp[j * n + i]);
                }
            }
        }

        return maxLength;
    }
};