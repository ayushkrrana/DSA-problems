#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canSplit(string numStr, int target, int sum, int index) {
        if (index == numStr.size()) return sum == target;
        
        int curr = 0;
        for (int i = index; i < numStr.size(); i++) {
            curr = curr * 10 + (numStr[i] - '0');
            if (canSplit(numStr, target, sum + curr, i + 1)) return true;
        }
        return false;
    }

    bool isValid(int x) {
        string squareStr = to_string(x * x);
        return canSplit(squareStr, x, 0, 0);
    }

    int punishmentNumber(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i)) total += (i * i);
        }
        return total;
    }
};
