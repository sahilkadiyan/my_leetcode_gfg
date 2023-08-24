class Solution {
public:
   
    int helper(vector<int>& a, vector<int>& b, int i,int prevA, int prevB, bool swap)
    {
        if(i==a.size()) return 0;
        int res=INT_MAX;
        
        // no swaps
        if(a[i]>prevA and b[i]>prevB)
            res=helper(a,b,i+1,a[i],b[i],0);
        // swaps
        if(b[i]>prevA and a[i]>prevB)
            res=min(res,helper(a,b,i+1,b[i],a[i],1)+1);
        return res;
    }
    
      int helperMemo(vector<int>& a, vector<int>& b, int i,int prevA, int prevB, bool swap,vector<vector<int>>&dp)
    {
        if(i==a.size()) return 0;
        if(dp[i][swap]!=-1) return dp[i][swap];
        int res=INT_MAX;
        
        // no swaps
        if(a[i]>prevA and b[i]>prevB)
            res=helperMemo(a,b,i+1,a[i],b[i],0,dp);
        // swaps
        if(b[i]>prevA and a[i]>prevB)
            res=min(res,helperMemo(a,b,i+1,b[i],a[i],1,dp)+1);
        return dp[i][swap]=res;
    }
    
    
    
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
         vector<vector<int>>dp(nums1.size()+1, vector<int>(2,-1));
        return helperMemo(nums1, nums2,0,-1,-1,0,dp);
        
        
        // return helper(nums1, nums2,0,-1,-1,0);
    }
};