class Solution {
public:
    bool isVowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    bool halvesAreAlike(string s) {
        size_t l = 0, r = s.size() - 1;
        size_t lc = 0, rc = 0;
        while (l < r) {
            lc += isVowel(s[l++]);
            rc += isVowel(s[r--]);
        }
        return lc == rc;
    }
};