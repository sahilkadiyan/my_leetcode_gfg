//in this question we are just traversing the whole vector and try to find out the maximum sum of the subarray which is continuous 
//time complexity: o(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_sofar=INT_MIN;
        int maxendinghere=0;
        for(int i=0;i<nums.size();i++){
            maxendinghere=maxendinghere+nums[i];
            if(max_sofar<maxendinghere){
                max_sofar=maxendinghere;
            }
            if(maxendinghere<0)
                maxendinghere=0;
        }
        return max_sofar;
    }
};