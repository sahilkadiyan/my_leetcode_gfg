class Solution {
public:
    void bfs(vector<vector<char>> & grid, int i, int j, int m, int n) {
        vector<int> dir = {-1,0,1,0,-1};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        
        while(!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();
            for(int k=0; k<4; k++) {
                int x = curr.first + dir[k], y = curr.second + dir[k+1];
                if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == '0') continue;
                grid[x][y] = '0';
                q.push({x,y});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res=0, m = grid.size(), n = m ? grid[0].size() : 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }
};