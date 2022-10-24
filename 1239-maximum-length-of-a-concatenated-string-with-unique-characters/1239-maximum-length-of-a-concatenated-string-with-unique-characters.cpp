class Solution {
public:
    int f[26];
    int maxLength(vector<string>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            memset(f, 0, sizeof f);
            int curr = 0;
            bool ok = true;
            for (int j = 0; j < n && ok; ++j) {
                if (i & (1 << j)) {
                    for (auto& c : arr[j]) {
                        ++f[c - 'a'];
                        if (f[c - 'a'] > 1) {
                            ok = false;
                        }
                    }
                    curr += arr[j].size();
                }
            }
            if (ok) {
                ans = max(ans, curr);
            }
        } 
        return ans;
    }
};