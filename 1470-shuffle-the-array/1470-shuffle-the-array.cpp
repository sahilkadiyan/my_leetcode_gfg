class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
          std::vector<int> returnVal;

        for(int i = 0; i < n; i++)
        {
            returnVal.emplace_back(nums[i]);
            returnVal.emplace_back(nums[i + n]);
        }

        return returnVal;
    }
};