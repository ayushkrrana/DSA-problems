class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        vector<int> freq(total + 1, 0);
        vector<int> ans(2);
        
        // Count frequency of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        
        // Find the repeated and missing numbers
        for (int i = 1; i <= total; i++) {
            if (freq[i] == 2) {
                ans[0] = i; // Repeated number
            }
            if (freq[i] == 0) {
                ans[1] = i; // Missing number
            }
        }
        
        return ans;
    }
};