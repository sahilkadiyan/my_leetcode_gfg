class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
      vector<int> v;
        int n=nums.size();
  int start=0;
  int end=n-1;

  int ans1=-1;
  
  //left 
  while(start<=end){
      
        int mid=start+(end-start)/2;
      if(nums[mid]==target){
          ans1=mid;
          end=mid-1;
      }
      else if(target>nums[mid]){
          start=mid+1;
      }
      else if(target<nums[mid]){
          end=mid-1;
      }
      mid=(start+end)/2;
  }
  v.push_back(ans1);
  
  
  //right
  int start1=0;
  int end1=n-1;
  
  int ans2=-1;
   while(start1<=end1){
       int mid1=start1+(end1-start1)/2;
      if(nums[mid1]==target){
          ans2=mid1;
          start1=mid1+1;
      }
      else if(target>nums[mid1]){
          start1=mid1+1;
      }
      else if(target<nums[mid1]){
          end1=mid1-1;
      }
      
  }
  v.push_back(ans2);
  return v;
    }
};