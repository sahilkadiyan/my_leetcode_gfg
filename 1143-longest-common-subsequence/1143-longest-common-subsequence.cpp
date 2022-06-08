//in this we simply start from the end in case of recursion whereas in case of tabulation we start filling then initial entry i.e all the 0th row and column will contain 0 length because there is no subsequence of 0 length now we use the previous values of the result 
//in recursion what we did firstly we compare the last character of both the strings then if they match then call for the other part of the string otherwise we need to compare all the characters of the string  
//take max of both the cases because it is possible thatb the last char of 1st string may match with the prev char of 2nd string that's why we reduce the size of one string ; so we  reduce the size of both the string one by one then pick up the max of both then return 
class Solution {
public:
    //recursion-o(2^n)
    
//     int helper(string text1,string text2,int m ,int n){
//         if(m==0 || n==0) return 0;
//         if(text1[m-1]==text2[n-1]){
//             return 1+helper(text1,text2,m-1,n-1);
//         }
//         else{
    
//             return max(helper(text1,text2,m-1,n),helper(text1,text2,m,n-1));
//         }
//     }
    
    
    
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int m=text1.length();
//         int n=text2.length();
//         return helper(text1,text2,m,n);
        
//     }
    
    
    
    //memoization -o(m*n) 
    
//         int helper(string text1,string text2,int m ,int n){
            
            
//             int mem[m+1][n+1];
//             for(int i=0;i<=m;i++){
//                 for(int j=0;j<=n;j++){
//                     mem[i][j]=-1;
//                 }
//             }
//             memset(mem, -1, sizeof(mem));
            
            
//             if(mem[m][n]!=-1){
//                 return mem[m][n];
                
//             }
//         if(m==0 || n==0) mem[m][n]=0;
//             else{
//         if(text1[m-1]==text2[n-1]){
//             mem[m][n]=  1+helper(text1,text2,m-1,n-1);
//         }
//         else{
//             mem[m][n]= max(helper(text1,text2,m-1,n),helper(text1,text2,m,n-1));
//         }
//     }
//             return mem[m][n];
//         }
//      int longestCommonSubsequence(string text1, string text2){
         
//            int m=text1.length();
//         int n=text2.length();
//         return helper(text1,text2,m,n);
//      }
    
    
    //tabulation -o(n)
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
    
};