class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       vector<int>v;
unordered_map<int,int>mp;
int n=nums.size();
int sum=0;
for(int i=0;i<nums.size();i++){
mp[nums[i]]++;
sum+=nums[i];
}

    for(auto it:mp){
      
        if(it.second>1){
            v.push_back(it.first);
      
    }
    }
    v.push_back((n*(n+1)/2)-sum+v[0]);
      
    return v;

}
};