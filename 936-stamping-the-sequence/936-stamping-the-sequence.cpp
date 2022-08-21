class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
         int n = size(target);
        int m = size(stamp);
        int prev_changed = -1;
        int changed = 0;
        int i, j, star;
        
        vector<int> res;
        res.reserve(n);
        
        while (prev_changed != changed and changed != n) {
            
            prev_changed = changed;
            
            for (i = 0; i <= n - m;) {
                
                for (j = 0, star = 0; j < m and i <= n - m; j++) {
                    if (target[i + j] == '*')
                        star++;
                    else if (stamp[j] != target[i + j])
                        break;
                }
                
                if (j == m and m > star) {
                    res.push_back(i);
                    memset(&target[i],'*', m);
                    changed += m - star;
                    i += m;
                }
                
                else {
                    i++;
                }
            }
        }
        
        if (changed != n)
            return vector<int>();
        
        reverse(begin(res), end(res));
        return res;
        
    }
};