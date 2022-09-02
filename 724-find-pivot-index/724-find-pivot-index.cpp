class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int s=0;
        int lsum=0;
        //calculate the whole sum of the array 
        if(nums.size()==0) return -1; //if the size of the array is 0 then return -1;
        
        
     for(int i=0;i<nums.size();i++) s=s+nums[i]; //that  is for calculating the sum of the whole array 
        //now we need to calculate lsum of the array and then check whether it is equal to whole sum array - value at a particular index if it is equal then return that index otherwise continue the loop 
        for(int i=0;i<nums.size();i++){
            if(lsum==s-lsum-nums[i]) return i; 
            lsum=lsum+nums[i]; //need to update lsum also 
        }
        return -1;
    }
};