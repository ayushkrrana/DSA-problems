#include <string>

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        while (s.find(part) != std::string::npos) {
            s.erase(s.find(part), part.length()); // Remove the first occurrence of part
        }
        return s;
    }
};
