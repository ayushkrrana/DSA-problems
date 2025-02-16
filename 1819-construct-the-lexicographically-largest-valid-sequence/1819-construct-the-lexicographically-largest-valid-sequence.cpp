class Solution {
public:
    vector<int> res;
    vector<bool> used;

    bool backtrack(int index, int n) {
        if (index == res.size()) return true; // Base case: all positions filled
        if (res[index] != 0) return backtrack(index + 1, n); // Skip filled positions

        for (int num = n; num >= 1; num--) { // Try placing largest numbers first
            if (used[num]) continue;
            int secondPos = (num > 1) ? (index + num) : index;

            if (secondPos < res.size() && res[secondPos] == 0) {
                res[index] = res[secondPos] = num;
                used[num] = true;
                
                if (backtrack(index + 1, n)) return true; // Proceed further

                // Backtrack if placement was incorrect
                res[index] = res[secondPos] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        res.resize(2 * n - 1, 0);
        used.resize(n + 1, false);
        backtrack(0, n);
        return res;
    }
};
