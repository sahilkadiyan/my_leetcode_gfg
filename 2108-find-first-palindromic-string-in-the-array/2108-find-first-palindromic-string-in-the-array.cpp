class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            string reversed = s;
            reverse(reversed.begin(), reversed.end());
            
            if (s == reversed) {
                return s;
            }
        }
        return "";
    }
};