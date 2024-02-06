class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0],votes=1;
        
        for(int i=1;i<nums.size();i++){
            if(votes==0){
                votes++;
                majority=nums[i];
            }
            else if(majority==nums[i]){
                votes++;
            }
            else{
                votes--;
            }
        }
        return majority;
    }
};