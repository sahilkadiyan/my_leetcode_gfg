class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(k==0){
            int maxi=INT_MIN;
            for(int n:vals)maxi=max(maxi,n);
            return maxi;
        }
        int n=vals.size();
        map<int,vector<pair<int,int>> > adj;
        for(auto p:edges){
            adj[p[0]].push_back({vals[p[1]], p[1]});
            adj[p[1]].push_back({vals[p[0]], p[0],});
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sort(adj[i].rbegin(),adj[i].rend());
            int kk=k;
            int sum=vals[i];
            maxi=max(maxi,sum);
            for(auto p:adj[i]){
                sum+=p.first;
                kk--;
                maxi=max(maxi,sum);
                if(kk==0 || p.first<0)break;
            }
        }
        return maxi;
    }
};