class Solution {
public:
    //this question is exactly similar to maximum sum of non-adjacent elements 
    //here ,this is the memoization approach , so first of all try to write the recusrive relation for the same then convert this into memoization (it would be easy)
    //basically we have two choices for an element i.e it to pick the element or don't pick it 

    // int f(int index, vector<int> & nums,vector<int> &dp){
    //     if(index==0) return nums[index];
    //     if(index<0) return 0;
    //     //if this index doesn't contain -1 then no need to do it again 
    //     if(dp[index]!=-1) return dp[index];
    //     int pick=nums[index]+f(index-2,nums,dp);
    //     int noPick=0+f(index-1,nums,dp);
    //     return dp[index]= max(pick,noPick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //initialize the dp with -1 of size n 
        // vector<int> dp(n,-1);
        // return f(n-1,nums,dp);
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int curri=max(take,notTake);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
        
        
        
    }
};