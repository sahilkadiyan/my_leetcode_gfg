class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         //just need to declare two variables i.e low and high 
         int low = 0, high = nums.size()-1;

        //run the loop until low<=high 
        while (low <= high) {
            int mid = low + (high-low)/2;
//if the number is less than target then low will be incremented 
            if (nums[mid] < target)
                low = mid+1;
            else
                //else high will be decremented 
                high = mid-1;
        }

      //at the end when we reach the target return the low not the high one because high one will point to a index which is less than the target's index because we terminate the loop when low crosses high and when we found the target 
        return low;
    }
};