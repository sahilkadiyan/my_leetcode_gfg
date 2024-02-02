class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
       int ans = 0;
       unordered_map<int, int> prefixSumCount;  // Use unordered_map for efficiency
       prefixSumCount[0] = 1;  // Initialize for empty subarray
       int currentSum = 0;

       for (int num : nums) {
           currentSum += num;
           int complement = currentSum - k;  // Find the complement to reach target sum
           if (prefixSumCount.count(complement)) {
               ans += prefixSumCount[complement];
           }
           prefixSumCount[currentSum]++;  // Increment count for current prefix sum
       }

       return ans;
   }
};