class Solution {
public:

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
     
//         vector<vector<int>> dp(m,vector<int>(m,-1));
      
//         for(int j=0;j<m;j++){
//             dp[m-1][j]=triangle[m-1][j];
//         }
        
//         for(int i=m-2;i>=0;i--){
//             for(int j=i;j>=0;j--){
//                 int down=triangle[i][j]+dp[i+1][j];
//                 int diagonal=triangle[i][j]+dp[i+1][j+1];
//                 dp[i][j]=min(down,diagonal);
//             }
//         }
//         return dp[0][0];
        
        
//     }
    
      int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int>front(m,0);
        vector<int>current(m,0);
      
        for(int j=0;j<m;j++){
         front[j]=triangle[m-1][j];
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+front[j];
                int diagonal=triangle[i][j]+front[j+1];
                current[j]=min(down,diagonal);
            }
            front=current;
        }
        return front[0];
        
        
    }
    
    
    
};