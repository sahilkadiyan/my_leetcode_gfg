class Solution {
    
public:
    //
    int dfs(int row, int col, vector<vector<int>>& grid)
    {
        //when ball come out.
        if(row>=grid.size())
        {
            return col;
        }
        //when ball go left to right.
        if(grid[row][col] == 1 && col+1<grid[0].size() && grid[row][col+1] == 1)
        {
            return dfs(row+1,col+1,grid);
        }
        //when ball is on last column so it can not going to the right size.
        else if(grid[row][col] == 1 && col+1>=grid[0].size())
        {
            return -1;
        }
        //when ball go to right to left.
        else if(grid[row][col] == -1 && col-1>=0 && grid[row][col-1] == -1)
        {
            return dfs(row+1,col-1,grid);
        }
        //when ball is on 1st column so it can not going to the left side.(this is last case so i not write code for it just put in else )
        else
        {
            return -1;
        }
    }
    
    //
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer(n);
        for(int col = 0; col < n ; col++)
        {
            answer[col] = dfs(0,col,grid);
        }
        return answer;
    }
};