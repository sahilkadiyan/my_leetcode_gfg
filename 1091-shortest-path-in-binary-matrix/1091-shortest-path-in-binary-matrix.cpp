class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
          int n = grid.size();
        if(n == 0) return -1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)   return -1;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = { {1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {-1,1}, {1,-1} };
        grid[0][0] = 1;
        q.push(make_pair(0,0));
        
        while(!q.empty())
        {
            auto cur = q.front();
            int x = cur.first;
            int y = cur.second;
            if(x == n -1 && y == n-1) return grid[x][y];
            
            for(auto d : dir){
                int nx = x+d.first;
                int ny = y+d.second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    grid[nx][ny] = 1 + grid[x][y];
                    q.push({nx,ny});
                }
            }
            q.pop();
        }
        return -1;
    }
};