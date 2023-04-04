class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map <int, int>mp;
vector<int> v;
   for(int i=0; i<nums.size(); i++)
      mp[nums[i]]++;
           priority_queue<pair<int,int>> pq;
       for(auto it=mp.begin(); it!=mp.end(); it++){
           pq.push({it->second,it->first});
           
       }
         for(int j=0;j<k;j++){
               auto ans1=pq.top();
               pq.pop();
           v.push_back(ans1.second);
           }
        return v;
     
        
      // cout<first<<" occurs "<second<<" times\n";
        
    }
};