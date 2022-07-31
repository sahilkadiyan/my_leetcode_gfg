class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //finding the candidate
        int res=0,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[res]==nums[i])
                count++;
            else
                count--;
            if(count==0){
                res=i;
                count=1; 
            }
        }
        
        count=0;
        for(int i=0;i<nums.size();i++)
            if(nums[res]==nums[i])
                count++;
        if(count<=nums.size()/2)
                res=-1;
        return nums[res];
            
        
        
        
    }
};