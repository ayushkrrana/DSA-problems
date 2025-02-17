class Solution {
public:
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, f] : freq) {
            if (f > 0) {
                count++;  // Count the current sequence
                freq[ch]--;  // Use the character
                count += backtrack(freq);  // Recurse
                freq[ch]++;  // Backtrack
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;  // Count frequency

        return backtrack(freq);
    }
};
