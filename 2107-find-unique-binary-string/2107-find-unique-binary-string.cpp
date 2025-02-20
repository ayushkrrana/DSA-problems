class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        
        // Constructing the unique binary string
        for (int i = 0; i < n; i++) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};
