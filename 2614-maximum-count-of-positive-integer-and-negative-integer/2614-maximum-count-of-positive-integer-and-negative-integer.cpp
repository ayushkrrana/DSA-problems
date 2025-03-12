class Solution {
public:
int count_pos=0;
int count_negative=0;
    int maximumCount(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
             count_pos+=1;
            }
            if(nums[i]<0){
                count_negative+=1;
            }
        }
        return max(count_pos,count_negative);
    }

};