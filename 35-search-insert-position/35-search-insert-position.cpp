//so first of all when we look at the time complexity of the code which is o(logn) we are sure that we need to solve this question using divide and conquer method and to guess which method or algo we need to use just read the question which said that we need to return the index when we found a target so it's quite clear that we need to use binary search which is quite easy !!!


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