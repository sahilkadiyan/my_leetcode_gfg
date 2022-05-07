// we can use set here because set do not contain any duplicate values and in the end comapre the size of set with the given array 
// if size of the set is less than the size of nums then return true i.e it conatins duplicate otherwise return false 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};