class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=0;
        int current=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) current=0;
            else{
                current++;
                result=max(current,result); 
            }
        }
        return result;
    }
};