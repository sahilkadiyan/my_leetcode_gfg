class Solution {
public:
    int normal_sum(vector<int> & nums){
        int res=nums[0],maxending=nums[0];
        for(int i=1;i<nums.size();i++){
            maxending=max(maxending+nums[i],nums[i]);
            res=max(res,maxending);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        //here we invert the array and apply the same principle as that of kadane's algo
        int max_normal=normal_sum(nums);
        if(max_normal<0) return max_normal;
        //circular sum
        int arr_sum=0;
        for(int i=0;i<nums.size();i++){
            arr_sum+=nums[i];  //array sum 
            nums[i]=-nums[i];
            
            
        }
        int max_circular=normal_sum(nums)+arr_sum;
        return max(max_circular,max_normal);
    }
};