class Solution {
public:
    unordered_set<int> sets;
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long curr = 0, last = 0;
        for (int i = 0; i < n; ++i) {
            curr += nums[i];
            int need = curr % k;
            if (sets.count(need)) {
                //cout << i << " " << curr << "  " << need << endl;
                return true;
            }
            sets.insert(last % k);
            last = curr;
        }
        return false;
    }
};