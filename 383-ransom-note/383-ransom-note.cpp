class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
          unordered_map<char,int>m;
        for(auto ch:magazine)
            m[ch]++;
        
        for(auto ch:ransomNote)
            m[ch]--;
        
        for(auto it:m)
            if(it.second<0)
                return false;
        return true;
    }
};