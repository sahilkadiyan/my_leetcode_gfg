class Solution {
    public int jobScheduling(int[] st, int[] et, int[] p) {
        int n=st.length;
        int l[][]=new int[n][3];
        for(int i=0;i<n;i++){
            l[i][0]=st[i];
            l[i][1]=et[i];
            l[i][2]=p[i];
        }
        Arrays.sort(l,(a,b)->a[0]-b[0]);
        int dp[]=new int[n];
        Arrays.fill(dp,-1);
        return solve(0,l,dp);
        
    }
    int solve(int i,int l[][],int dp[]){
        if(i==l.length)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int high=l.length-1;
        int low=i+1;
        int idx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(l[mid][0]>=l[i][1]){
                idx=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        int op1=solve(idx,l,dp)+l[i][2];
        int op2=solve(i+1,l,dp);
        return dp[i]=Math.max(op1,op2);
    }
}