class Solution {
public:
    string breakPalindrome(string palindrome) {
           size_t sz = palindrome.size();
        if (sz <= 1) return "";
        
        for (size_t i=0; i < sz/2; i++) {
            if (palindrome[i] > 'a')  {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[sz-1] = 'b';
        return palindrome;
    }
};