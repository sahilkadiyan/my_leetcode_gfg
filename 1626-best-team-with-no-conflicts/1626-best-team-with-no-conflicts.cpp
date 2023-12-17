class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       
int n=ages.size();
vector dp(n,0);
vector<pair<int,int>> vp;
for(int i=0; i<n; i++) vp.push_back({ages[i],scores[i]});
sort(vp.begin(),vp.end());
for(int i=0; i<n; i++){
dp[i] = vp[i].second;
for(int j=0; j<i; j++){
if(vp[i].second>=vp[j].second){
dp[i] = max(dp[i], dp[j] + vp[i].second);
}
}
}
return *max_element(dp.begin(),dp.end());
    }
};