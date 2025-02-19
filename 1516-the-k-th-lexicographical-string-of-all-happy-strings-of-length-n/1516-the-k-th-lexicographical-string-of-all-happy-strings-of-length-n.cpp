class Solution {
public:
    void generateHappyStrings(string &current, vector<string> &happyStrings, int n) {
        if (current.size() == n) {
            happyStrings.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) { 
                current.push_back(ch);
                generateHappyStrings(current, happyStrings, n);
                current.pop_back();  
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current;
        
        generateHappyStrings(current, happyStrings, n);
        
        return k <= happyStrings.size() ? happyStrings[k - 1] : "";
    }
};
