class Solution {
public:
    string traverse(string curr) {
        string ans;
        int cnt = 1, n = curr.size();
        char ch = curr[0];
        for (int i = 1; i < n; ++i) {
            if (curr[i] != ch) {
                ans.push_back((char)(cnt + '0'));
                ans.push_back(ch);
                ch = curr[i];
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        ans.push_back((char)(cnt + '0'));
        ans.push_back(ch);
        return ans;
    }

    string countAndSay(int n) {
        string curr = "1";
        for (int i = 2; i <= n; ++i) {
            curr = traverse(curr);    
        } 
        return curr;
    }
};