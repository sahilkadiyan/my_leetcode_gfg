class Solution {
public:
    //time complexity:o(n)
    //space complexity:o(1)
    
    vector<int> runningSum(vector<int>& nums) {
        
        
      if (nums.begin() == nums.end()) return nums;
        for(int i = 1 ; i < nums.size(); ++i){
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};