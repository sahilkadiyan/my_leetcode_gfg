class Solution {
public:
     void dfs(vector<vector<int>>& M, vector<vector<int>>& vis, int i, int j) {
        int m = M.size(), n = M[0].size();
        // marked this cell (i, j) as visited
        // so that we won't visit it again
        vis[i][j] = 1;
        // perform DFS on the left cell
        if (i - 1 >= 0 && !vis[i - 1][j] && M[i - 1][j] >= M[i][j]) dfs(M, vis, i - 1, j);
        // perform DFS on the right cell
        if (i + 1 < m && !vis[i + 1][j] && M[i + 1][j] >= M[i][j]) dfs(M, vis, i + 1, j);
        // perform DFS on the top cell
        if (j - 1 >= 0 && !vis[i][j - 1] && M[i][j - 1] >= M[i][j]) dfs(M, vis, i, j - 1);
        // perform DFS on the bottom cell
        if (j + 1 < n && !vis[i][j + 1] && M[i][j + 1] >= M[i][j]) dfs(M, vis, i, j + 1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& M) {
        vector<vector<int>> ans;
        int m = M.size(), n = M[0].size();
        // P[i][j] = 1 means it is able to flow to pacific ocean
        vector<vector<int>> P(m, vector<int>(n));
        // A[i][j] = 1 means it is able to flow to atlantic ocean
        vector<vector<int>> A(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            // perform dfs starting from the left-most column 
            dfs(M, P, i, 0);
            // perform dfs starting from the right-most column 
            dfs(M, A, i, n - 1);
        }
        for(int i = 0; i < n; i++) {
            // perform dfs starting from the top-most row
            dfs(M, P, 0, i);
            // perform dfs starting from the bottom-most row
            dfs(M, A, m - 1, i);
        }
        // iterate each row
        for(int i = 0; i < m; i++) {
            // iterate each column
            for(int j = 0; j < n; j++) {
                // if both P[i][j] & A[i][j] are visited
                // that means this cell can flow to both ocean
                if(P[i][j] && A[i][j]) {
                    // then put the coordinate (i, j) to answer
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};