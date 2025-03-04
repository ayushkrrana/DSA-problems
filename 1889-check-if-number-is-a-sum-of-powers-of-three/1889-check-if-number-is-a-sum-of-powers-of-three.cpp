class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            int rem = n % 3;  // Get remainder when divided by 3
            if (rem == 2) {
                return false; // If remainder is 2, then it's not possible
            }
            n /= 3; // Divide the number by 3
        }
        return true;
    }
};
