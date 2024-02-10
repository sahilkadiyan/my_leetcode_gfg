class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> p;
        //1st value is xi-yi and 2nd value is xi
        
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){
            
            //if xj-xi> k 
            while(!p.empty() && (points[i][0]-p.top().second)>k) p.pop();
            
            if(!p.empty()){
                ans=max(ans,points[i][0]+points[i][1]+p.top().first);
            }
            
            p.push({points[i][1]-points[i][0],points[i][0]});
        }
        
        return ans;
    }
};