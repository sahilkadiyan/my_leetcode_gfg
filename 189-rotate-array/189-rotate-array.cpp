#include<vector>
#include <algorithm>
class Solution {
public:
 
    void rotate(vector<int>& nums, int k) {
    
        int n=nums.size();
        reverse(nums.begin(),nums.begin()+n);
    reverse(nums.begin(),nums.begin()+k%n);
    reverse(nums.begin()+k%n,nums.begin()+n);
    }
};