class Solution {
public:
    // time complexity:o(n*n)
    //space complexity:o(n)
    int lengthOfLIS(vector<int>& nums) {
        int lis[nums.size()];
        //filling the lis array
        lis[0]=1;
        for(int i=1;i<nums.size();i++){
            lis[i]=1; //intialize this with value 1 
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        //this is just for finding out the max from the lis array
        int res=lis[0];
        for(int i=0;i<nums.size();i++){
            res=max(res,lis[i]);
        }
        return res;
        
        
    }
};