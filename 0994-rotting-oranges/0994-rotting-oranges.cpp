class Solution {
public: 
    void recurdfs(int x, int y, int level, std::vector<vector<int>>& time, vector<vector<int>>& grid) {
        if (x < 0 || x >= time.size() || y < 0 || y >= time[0].size()) {
            return; // Bad case, return, out of bounds!!
        }
        
        // If this element is not orange, return bruh
        if (grid[x][y] == 0) {
            return;
        }
        
        // Visit this node, ie find the minimum value, if this node has been previously visited
        // If node has been previously visited by time < current, return
        if (time[x][y] <= level) {
            return;
        }
        
        // No, we found better time, so set that time to be reachability of this array
        time[x][y] = level;
        
        // Now do the same recursion for all 4 directions!
        recurdfs(x - 1, y, level + 1, time, grid);
        recurdfs(x + 1, y, level + 1, time, grid);
        recurdfs(x, y - 1, level + 1, time, grid);
        recurdfs(x, y + 1, level + 1, time, grid);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
       vector<std::vector<int>> time(grid.size(), std::vector<int>(grid[0].size(), INT_MAX));
        
        bool does_it_have_one = false;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    // If this is a rotten orange, start our dfs visiting algo
                    recurdfs(i, j, 0, time, grid);
                }
                
                if (grid[i][j] == 1) {
                    does_it_have_one = true;
                }
            }
        }
        
        // Corner case, have no 1s, so time to rot everything is 0.
        if (!does_it_have_one) {
            return 0;
        }
        
        // std::cout << "\n" << time;
        
        int max_time = INT_MIN;
        // Find the maximum time required, and that will be our answer!
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int grid_element = grid[i][j];
                int time_to_reach = time[i][j];
                if (grid_element == 1) {
                    // Corner case, if time to reach a fresh orange is still infinity (ie int max val), it implies
                    // that it cannot be reached or rotten, thus return -1
                    if (time_to_reach == INT_MAX) {
                        return -1;
                    }
                    
                    max_time = max(max_time, time_to_reach);
                }
            }
        }
        
        return max_time;
    }
};