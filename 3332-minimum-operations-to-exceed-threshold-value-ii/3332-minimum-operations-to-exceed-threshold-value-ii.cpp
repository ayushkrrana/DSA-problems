#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (minHeap.size() > 1 && minHeap.top() < k) {
            long long x = minHeap.top(); minHeap.pop();
            long long y = minHeap.top(); minHeap.pop();
            
            long long newValue = (min(x, y) * 2LL) + max(x, y);  // Prevent overflow
            minHeap.push(newValue);
            operations++;
        }

        return minHeap.top() >= k ? operations : -1;
    }
};
