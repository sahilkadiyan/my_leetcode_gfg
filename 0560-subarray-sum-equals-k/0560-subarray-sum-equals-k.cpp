class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
       int ans = 0;
       unordered_map<int, int> map;  // Use unordered_map for efficiency
       map[0] = 1;  // Initialize for empty subarray
       int sum = 0;

       for (int num : nums) {
           sum += num;
           if (map.count(sum-k)) {
               ans += map[sum-k];
           }
           map[sum]++;  // Increment count for current prefix sum
       }

       return ans;
   }
};