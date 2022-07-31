class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans=nums[0]; //initially our result is 1st element of the array 
        int maxending=nums[0]; //prev sum of the subarray
        for(int i=1;i<nums.size();i++){
            maxending=max(maxending+nums[i],nums[i]);
            ans=max(ans,maxending);
        }
        return ans;
    }
};