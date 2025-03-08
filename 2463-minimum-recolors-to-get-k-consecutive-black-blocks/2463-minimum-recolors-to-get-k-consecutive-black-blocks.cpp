class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minOperations = k; // Maximum operations needed can be k (worst case)
        int whiteCount = 0;

        // Count white blocks in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }
        minOperations = whiteCount;

        // Slide the window across the string
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') whiteCount--; // Remove leftmost block
            if (blocks[i] == 'W') whiteCount++;     // Add rightmost block
            minOperations = min(minOperations, whiteCount);
        }

        return minOperations;
    }
};
