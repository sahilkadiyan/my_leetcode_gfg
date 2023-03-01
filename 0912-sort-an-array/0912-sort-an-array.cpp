class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));  // seed random number generator
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void insertion_sort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int j = i;
            while (j > left && nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }

    void qsort(vector<int>& nums, int left, int right) {
        if (left >= right) return;  // base case: subarray has size 0 or 1
        if (right - left + 1 <= 16) {  // use insertion sort for small subarrays
            insertion_sort(nums, left, right);
            return;
        }

        // choose random pivot
        int pivot_index = left + rand() % (right - left + 1);
        int pivot = nums[pivot_index];

        int i = left, j = right;
        while (i <= j) {
            while (nums[i] < pivot) i++;  // find element on left to swap
            while (nums[j] > pivot) j--;  // find element on right to swap
            if (i <= j) {
                swap(nums[i], nums[j]);  // swap elements and move indices
                i++;
                j--;
            }
        }

        qsort(nums, left, j);   // recursively sort left subarray
        qsort(nums, i, right);  // recursively sort right subarray
    }


};