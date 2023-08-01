class Solution {
public:
    void helper(int indx,int n, int k,vector<vector<int>>&ans,vector<int>&v)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        for(int i=indx;i<n+1;i++)
        {
            v.push_back(i);
            helper(i+1,n,k,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(1,n,k,ans,v);
        return ans;
    }
};