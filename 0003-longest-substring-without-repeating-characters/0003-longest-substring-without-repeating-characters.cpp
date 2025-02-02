class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1); 
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            if (charIndex[s[right]] != -1) {
                left = max(left, charIndex[s[right]] + 1);
            }
            charIndex[s[right]] = right; 
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
