class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;   //count the number of suybarrays 
        
        unordered_map<int ,int> map;
        map[0]=1;  //this 1 is the frequencey of the remainder which is 0 initially 
        int sum=0;
        int rem=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            
            if(rem<0){
                rem+=k;
            }
            
            if(map.find(rem)!=map.end()){
                ans+=map[rem];  //stroing the freq in the final result 
                map[rem]++;   //incrementing the frequency of the remainder in the map
            }
            else{
                map[rem]=1;
            }
        }
        
        return ans;
        
        
        
        
        
      
    }
};
