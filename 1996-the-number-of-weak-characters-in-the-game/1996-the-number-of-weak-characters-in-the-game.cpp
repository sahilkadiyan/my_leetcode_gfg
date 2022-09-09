class Solution {
public:
    
    
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0] > b[0])
            return true;
        else if(a[0] == b[0]){
            if(a[1] < b[1])
                return true;
        }
        return false;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        // for(int i = 0;i < properties.size();i++){
        //     cout << properties[i][0] << " " << properties[i][1] << endl;
        // }
        int cnt = 0;
        int max_def = 0,max_att = 0;
        for(int i = 0;i < properties.size();i++){
            if(properties[i][0] > max_att){
                max_att = properties[i][0];
            }
            if(properties[i][1] > max_def){
                max_def = properties[i][1];
            }
            if(properties[i][0] < max_att && properties[i][1] < max_def){
                cnt++;
            }
        }
        return cnt;
    }
};