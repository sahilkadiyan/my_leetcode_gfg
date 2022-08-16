#include<unordered_map>
#include<string>
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ourmap;
        for(int i=0;i<s.length();i++){
            ourmap[s[i]]++;
        }
        int count=0;
        for(int i=0;i<s.length();i++){
            if(ourmap[s[i]]==1){
                
              return i;
            }
         
    }
        return -1;
    }
};