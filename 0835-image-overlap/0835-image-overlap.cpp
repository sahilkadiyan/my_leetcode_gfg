class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        map<pair<int, int>, int> cnt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) {
                    for (int ii = 0; ii < n; ++ii) {
                        for (int jj = 0; jj < n; ++jj) {
                            if (img2[ii][jj] == 1) {
                                cnt[{i - ii, j - jj}]++;
                            }
                        }
                    }
                }
            }
        }
        for (auto& it : cnt) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};