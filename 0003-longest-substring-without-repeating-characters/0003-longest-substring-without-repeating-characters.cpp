class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1); // Stores last index of characters
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            if (charIndex[s[right]] != -1) {
                left = max(left, charIndex[s[right]] + 1); // Move left if duplicate found
            }
            charIndex[s[right]] = right; // Update last index of character
            maxLength = max(maxLength, right - left + 1); // Update max length
        }
        return maxLength;
    }
};
