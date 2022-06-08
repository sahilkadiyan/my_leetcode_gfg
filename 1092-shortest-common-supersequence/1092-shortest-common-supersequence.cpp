//so first of all find the lcs and then fulfill the other conditions too !!!
//this is clearly expalined with comments along with each line !!!
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
          //here this is the string for storing the resultant string 
          //here we are backtracking from the bottom to the up that's why we need to reverse the string too at the end !!! 
          //so initialize i with m and j with n and run the loop until they both become zero 
          
          string s;
          int i=m,j=n,index=dp[m][n];
          while(i>0 && j>0){
              if(text1[i-1]==text2[j-1]){
                  //here when we find both the string char equal and then add it to the string s 
                  s=s+text1[i-1];
                  i--;
                  j--;
              }
              else{
                  //when we don't find any equal char then take the step towards that cell which has maximum value because we come to this position by picking the max value na !!!!!!!!!!
                  if(dp[i-1][j]>dp[i][j-1])
                      i--;
                  else
                      j--;
              }
          }
          //reverse the string 
           reverse(s.begin() , s.end());
          return s;

          
          
     
        
          }
         
    string shortestCommonSupersequence(string str1, string str2) {
        //res is the resultant string 
        string res;
        string y=longestCommonSubsequence(str1,str2);
        int a =str1.length();
        int b=str2.length();
       int k=0;
        int i=0;
        int j=0;
        //run the loop until we reach the length of both the string and until k becomes equal to the length of the longest common subsequence (LCS)
        while(i<a && j<b && k<y.length()){
            //if 1st char of both the string are equal and also equal to the 1st char of lcs then simply add the first char of lcs to res string 
            if(str1[i]==str2[j] && str1[i]==y[k]){
                res=res+y[k];
                i++;
                j++;
                k++;
            }
            //if above condition is not satisfied then check for individual string 
            else{
                //if 1st char of str1 is equal to 1st char of lcs string then add str2 to the res string 
                if(str1[i]==y[k])
                    res=res+str2[j++];
                else
                    res=res+str1[i++];
            }
        }
        
        //this loop is for the remaining part of the string just in case some chars left in a particular string !!!
        while(i<a){
            res=res+str1[i++];
        }
        while(j<b){
            res=res+str2[j++];
        }
        return res;
  
   
        
    }
};