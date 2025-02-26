class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, sum = 0;
        int maxAns = 0, minAns = 0;

        for (int num : nums) {
            sum += num;
            maxSum = max(num, maxSum + num);
            minSum = min(num, minSum + num);
            
            maxAns = max(maxAns, maxSum);
            minAns = min(minAns, minSum);
        }

        return max(abs(maxAns), abs(minAns));
    }
};
