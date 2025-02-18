class Solution {
public:
    bool isPalindrome(long long x) {
        long long original=x;
        long long reverse=0;
        while(x>0){
            long long last_digit=x%10;
            x=x/10;
            reverse=reverse*10+last_digit;
        }
        if(reverse==original){
            return true;
        }
        else{
            return false;
        }
    }
};