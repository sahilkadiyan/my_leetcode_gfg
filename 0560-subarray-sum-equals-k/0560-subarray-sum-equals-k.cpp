class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
       int count = 0;
       int n = nums.size();

       for (int i = 0; i < n; i++) {
           int currentSum = 0;
           for (int j = i; j < n; j++) {
               currentSum += nums[j];
               if (currentSum == k) {
                   count++;
               }
           }
       }

       return count;
   }
};