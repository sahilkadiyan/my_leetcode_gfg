//this problem is just the variation of lcs of what we do in the question find the 
class Solution {
public:
      int longestCommonSubsequence(string text1, string text2){
           int m=text1.length();
        int n=text2.length();
             int dp[m+1][n+1];
           //fill the 0th row and column with values 0
           for(int i=0;i<=m;i++){
               dp[i][0]=0;
           }
            for(int i=0;i<=n;i++){
               dp[0][i]=0;
           }
           for(int i=1;i<=m;i++){
               for(int j=1;j<=n;j++){
                   if(text1[i-1]==text2[j-1]){
                       //if char matches then add 1 to the diagonal element then store it 
                       dp[i][j]=1+dp[i-1][j-1];
                   }
                   else{
                       //pick the max of two i.e non diagonal values 
                       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                   }
               }
           }
           return dp[m][n];
      }
    
    
    int longestPalindromeSubseq(string s) {
        string s1=s;
reverse(s1.begin(),s1.end());
        return longestCommonSubsequence(s,s1);
    }
};