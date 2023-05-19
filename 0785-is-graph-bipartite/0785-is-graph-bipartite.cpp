class Solution {
public:
    bool helper(int depth, int k, vector<short>& status, vector<vector<int>>& neighbors) {
        status[k] = depth;
        for (int i = 0; i < neighbors[k].size(); i++) {
            if (!status[neighbors[k][i]]) {
                if (!helper(-depth, neighbors[k][i], status, neighbors)) {
                    return false;
                }
            }
            else if (status[neighbors[k][i]] == depth) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& edges) {
        vector<short> status(edges.size(), 0);
        for (int k = 0; k < edges.size(); k++) {
            if (!status[k] || status[k] == 1) {
                if (!helper(1, k, status, edges)) {
                    return false;
                }   
            }
        }
        return true;
    }
};