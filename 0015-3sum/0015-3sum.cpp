class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty() || nums.size()<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        
        set<vector<int>> result;
        
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;
            
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(sum==0){
                    result.insert({nums[i],nums[left],nums[right]});
                    
                    ++left;
                    --right;
                }
                else if(sum<0) left++;
                else right--;
            }
        }
        
        return vector<vector<int>>(result.begin(),result.end());
        
    }
};