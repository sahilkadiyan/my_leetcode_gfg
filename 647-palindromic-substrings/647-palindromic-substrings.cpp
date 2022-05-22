class Solution {
public:
    int countSubstrings(string s) {
        
         int n = s.length();
        int ans = n;
        for(int i=0;i<n;i++) {
            // Cover odd length.
            int j = i-1, k = i+1;
            while(j>=0 && k< n && (s[j--] == s[k++])) ans++;
            
            // Cover even length.
            j = i, k = i+1;
            while(j>=0 && k< n && (s[j--] == s[k++])) ans++;
        }
        
        return ans;
    }
};