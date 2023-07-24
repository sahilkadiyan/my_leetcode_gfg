class Solution {
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        dp = vector(len+1,-1);
        return dfs(nums,0,len);
    }

    int dfs(vector<int>& nums, int index , int len){
        if(index>=len) return 0;
        if(dp[index]!=-1) return dp[index];
        int x = nums[index]+dfs(nums,index+2,len);
        return dp[index] = max(x,dfs(nums,index+1,len));
    }
    
};