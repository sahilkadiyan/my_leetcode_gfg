class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
          sort(nums.begin(),nums.end()); int n=nums.size();
		int ans=INT_MAX; int op=0;
		for(int i=0;i<n-2;i++)  
		{
			int j=i+1; int k=n-1; 
			while(j<k)
			{
				int sum=nums[i]+nums[j]+nums[k];

				 if(abs((sum)-target)<ans)
				 {
					 ans=abs(sum-target);
					 op=sum;
					 if(sum==target) return op;
				 }
				(sum > target) ? k-- : j++;
			}
		}
		return op;
    }
};