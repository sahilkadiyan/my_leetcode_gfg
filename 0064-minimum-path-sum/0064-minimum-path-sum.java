class Solution {
    public int minPathSum(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0){
            return 0;
        }
        int row = grid.length;
        int columns = grid[0].length;

        //init
        int [][] dp = new int [row+1][columns+1];
        for(int i=0;i<columns;i++){
            dp[1][i+1] = dp[1][i]+grid[0][i];
        }
        for(int i=0;i<row;i++){
            dp[i+1][1] = dp[i][1]+grid[i][0];
        }
        
        // calculate
        for(int i=1;i<row;i++){
            for(int j=1;j<columns;j++){
                dp[i+1][j+1] = Math.min(dp[i][j+1],dp[i+1][j])+grid[i][j];
            }
        }
        return dp[row][columns];
    }
}