#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] != '0') return false; // If the last index is '1', we can't reach it

        queue<int> q;
        q.push(0); // Start from index 0
        int farthest = 0; // Tracks the farthest visited index

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // Explore jump range from i + minJump to i + maxJump
            for (int j = max(i + minJump, farthest + 1); j <= min(i + maxJump, n - 1); j++) {
                if (s[j] == '0') {
                    if (j == n - 1) return true; // If we reach the last index, return true
                    q.push(j);
                }
            }

            farthest = min(i + maxJump, n - 1); // Update the farthest index reached
        }

        return false;
    }
};
