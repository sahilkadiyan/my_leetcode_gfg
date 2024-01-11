class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0];
        int fast=nums[0];
        
        //1st collision
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]]; 
        } while(slow!=fast);
        
        //2nd collision
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};