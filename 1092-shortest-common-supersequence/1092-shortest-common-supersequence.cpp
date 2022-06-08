class Solution {
public:
    //this is to find out the lcs
      string longestCommonSubsequence(string text1, string text2){
          // string x;
          int k=0;
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
                       // x[k]=text1[i-1];
                       k++;
                   }
                   else{
                       //pick the max of two i.e non diagonal values 
                       dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                   }
               }
           }
          string s;
          int i=m,j=n,index=dp[m][n];
          while(i>0 && j>0){
              if(text1[i-1]==text2[j-1]){
                  s=s+text1[i-1];
                  i--;
                  j--;
              }
              else{
                  if(dp[i-1][j]>dp[i][j-1])
                      i--;
                  else
                      j--;
              }
          }
          
           reverse(s.begin() , s.end());
          return s;

          
          
     
        
          }
           // return dp[m][n];
         
           
     
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        string res;
        string y=longestCommonSubsequence(str1,str2);
        int a =str1.length();
        int b=str2.length();
       int k=0;
        int i=0;
        int j=0;
        while(i<a && j<b && k<y.length()){
            if(str1[i]==str2[j] && str1[i]==y[k]){
                res=res+y[k];
                i++;
                j++;
                k++;
            }
            else{
                if(str1[i]==y[k])
                    res=res+str2[j++];
                else
                    res=res+str1[i++];
            }
        }
        while(i<a){
            res=res+str1[i++];
        }
        while(j<b){
            res=res+str2[j++];
        }
        return res;
  
   
        
    }
};