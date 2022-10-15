class Solution {
public:
    int n, tar;
    string s;
    int memo[110][110];
    
    // the result which the string with a length of cnt(same character) will be compressed
    inline int calc(int cnt) {
        if (cnt == 1) {
            return 1;
        }
        if (cnt > 1 && cnt < 10) {
            return 2;
        }
        if (cnt >= 10 && cnt < 100) {
            return 3;
        }
        if (cnt >= 100) {
            return 4;
        }
        return 1e9;
    }
    
    // cnt--> the number of characters which have been chosen  idx--> the index where we start to choose in this phase
    int dfs(int idx, int cnt) {
        if (idx == n) {
            if (cnt >= tar) {
                return 0;
            } else {
                // we haven't choose enough character (cnt < n - k)
                return 1e9;
            }
        }
        if (memo[idx][cnt] != -1) {
            return memo[idx][cnt];
        }
        int ret = 1e9;
        char ch = s[idx];
        int curr = 0;
        // enum in this phase, how many characters which is the same as s[idx] we will choose
        for (int i = idx; i < n; ++i) {
            if (s[i] == ch) {
                ++curr;
                ret = min(ret, calc(curr) + dfs(i + 1, cnt + curr));
            }
        }
        // we give up choosing this character, then we will skip to the next
        ret = min(ret, dfs(idx + 1, cnt));
        memo[idx][cnt] = ret;
        return ret;
    }
    
    // the problem is that, calculate the minimal length after compression when we choose at least n - k characters in the string
    // solve by memorial dfs
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        this->n = s.size();
        this->tar = n - k;
        memset(memo, -1, sizeof memo);
        return dfs(0, 0);
    }
};