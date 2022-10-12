class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=nums.size()-1; i>=2; i--){
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[i-2];
            
            if(a+b > c and b+c > a and a+c > b){
                return a+b+c;
            }
        }
        return 0;
    }
};