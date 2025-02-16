#include<bits/stdc++.h>
class Solution {
public:
    int reverse(int n) {
        int reverse=0;
        while(n!=0){
            int last_digit=n%10;
            if(reverse>INT_MAX/10 || reverse<INT_MIN/10){// we divide by 10 to check early to prevent overflow because int can only store upto 32 bit so we take one less digit by/10 to check
                return 0;
            }
            n=n/10;
            reverse=reverse*10+last_digit;
        }
        return reverse;
    }
};