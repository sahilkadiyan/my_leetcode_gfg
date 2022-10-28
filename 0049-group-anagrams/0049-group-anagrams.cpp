class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         set<vector<int>>st;
        map<vector<int>,vector<int>>mpp;
        for(int i = 0;i < strs.size();i++){
            vector<int>arr(26);
            for(int j = 0;j < strs[i].length();j++){
                arr[strs[i][j]-'a']++;
            }
            mpp[arr].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it : mpp){
            vector<string>temp;
            for(auto it2 : it.second){
                temp.push_back(strs[it2]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};