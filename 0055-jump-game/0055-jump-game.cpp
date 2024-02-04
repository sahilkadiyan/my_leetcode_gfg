class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalPosition=nums.size()-1;
        
        for(int idx=nums.size()-2;idx>=0;idx--){
            
            if(idx+nums[idx]>=finalPosition){
                finalPosition=idx;
            }
        }
        return finalPosition==0;
    }
};