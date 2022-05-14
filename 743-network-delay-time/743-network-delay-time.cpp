class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n+1);
        for(int i=0;i<times.size();i++){
            v[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        int time[n+1];
        fill_n(time,n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        int ans=0;
        time[k]=0;
        
            while(!q.empty()){
                int val=q.top().second;
                q.pop();
                for(auto it : v[val]){
                    if(time[val]+it.second < time[it.first]){
                        time[it.first] = time[val]+it.second;
                        q.push({time[it.first],it.first});
                    }
                    
                }
            }
        
        for(int i=1;i<=n;i++){
            if(time[i] == INT_MAX) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};