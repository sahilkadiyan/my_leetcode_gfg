class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        
         int ans = 0, i, n = nums.size();
        
        for(i=0; i<n; ++i)
            ans ^= i ^ nums[i];
        
        return ans ^ i;
    }
};