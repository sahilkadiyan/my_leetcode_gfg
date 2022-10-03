class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
         int mx = neededTime[0];
        int res = 0, cursum = neededTime[0];
        for (int i=1;i<colors.size();i++){
            if (colors[i]==colors[i-1]){
                cursum += neededTime[i];
                mx = max(mx , neededTime[i]);
            }
            else{
                res += cursum - mx;
                cursum = mx = neededTime[i];
            }
        }
        res += cursum - mx;
        return res;
    }
};