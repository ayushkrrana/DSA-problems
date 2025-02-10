#include <stack>
#include <string>

class Solution {
public:
    std::string clearDigits(std::string s) {
        std::string stack;
        
        for (char c : s) {
            if (isdigit(c)) {
                if (!stack.empty()) {
                    stack.pop_back(); // Remove last non-digit character
                }
            } else {
                stack.push_back(c); // Add non-digit to stack
            }
        }
        
        return stack;
    }
};
