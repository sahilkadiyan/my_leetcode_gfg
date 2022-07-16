class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int s=0;
        int lsum=0;
        //calculate the whole sum if the array 
     for(int i=0;i<nums.size();i++) s=s+nums[i];
        for(int i=0;i<nums.size();i++){
            if(lsum==s-lsum-nums[i]) return i; 
            lsum=lsum+nums[i]; //need to update lsum also 
        }
        return -1;
    }
};