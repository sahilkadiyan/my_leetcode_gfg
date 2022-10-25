class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
         int i = 0;
        int j = 0;
        int k = 0;
        int l = 0;
        
        while(i < word1.size() && j < word2.size()) {
            
            while(k < word1[i].length() && l < word2[j].length()) {
                
                if(word1[i][k] != word2[j][l])
                    return false;
                
                k++;
                l++;
            }
            
            if(k == word1[i].length()) {
                
                i++;
                k = 0;
            }
            
            if(l == word2[j].length()) {
                
                j++;
                l = 0;
            }   
        }
        
        if(i == word1.size() && j == word2.size())
            return true;
        
        return false;
    }
};