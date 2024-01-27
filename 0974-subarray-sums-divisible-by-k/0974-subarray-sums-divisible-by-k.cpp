class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int ans = 0;

        std::unordered_map<int, int> map;
        map[0] = 1;

        int sum = 0;
        int rem = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            if (map.find(rem) != map.end()) {
                ans += map[rem];
                map[rem]++;
            } else {
                map[rem] = 1;
            }
        }

        return ans;
    }
};
