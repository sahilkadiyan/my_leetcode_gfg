//this problem can simply be solved with the help of sets and hashmaps we prefer to use maps so that it can give o(1) space complexity 
//firstly unordered map will be of element + it's index like <element of array , index> just like that so first step is just like if the frequency i.e the count of the element is 0 then we will store its corresponding index in hash[nums[i]] and in just case there appears the repetitive element then we will check the condition given in the question i.e abs(i-j)<=k if it's true then return true otherwise keeps adding all the elements with index in the hashmap unitil we traverse the whole array or vector 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //map creation with <element,index>
        unordered_map<int,int> hash;
        //traversing the vector
    for (int i = 0; i <nums.size();i++)
    {
        //count is 0 or not if it is 0 add it to the hashmap
        if (hash.count(nums[i]) == 0)
            hash[nums[i]] = i;
        
        //condition is being checked if count is not zero 
        else if (i - hash[nums[i]] <=k)
            return true;
        //if still the count is not zero + the condition is not satisfied then keeps on adding the element until we traverse the whole vector 
        else
            hash[nums[i]] = i;
    }
    
    return false;
        
    }
};