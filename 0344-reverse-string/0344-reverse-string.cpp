class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>temp;// if we not use this vector than the push back is done in the original vector in which the previous value is already present 
        for(int i=s.size()-1;i>=0;i--){
            temp.push_back(s[i]);
        }
       s=temp;
    }
};