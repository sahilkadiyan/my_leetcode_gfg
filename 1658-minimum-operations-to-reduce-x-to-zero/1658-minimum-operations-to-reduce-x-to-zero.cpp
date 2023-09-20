class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;

        int L = 0, R = 0, maxn = -1;
        while(R < n) {
            target -= nums[R++];
            while(target < 0) target += nums[L++];
            if(target == 0) maxn = max(maxn, R - L);
        }
        return (maxn == -1) ? maxn : n - maxn;
    }
};