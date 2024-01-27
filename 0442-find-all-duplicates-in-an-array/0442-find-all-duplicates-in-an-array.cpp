class Solution {
public:
    
    //TC: O(N)
    //SC: O(1)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i])-1;
            //if the number is negative this means we are encountering this element again 
            if(nums[index]<0)
                ans.push_back(index+1);
                
            
            nums[index]=nums[index]*-1;
        }
        
        return ans;
        
    }
};