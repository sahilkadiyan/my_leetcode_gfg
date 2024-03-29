class Solution {
public:
    bool isPermutation(string &s,string &t){
        //creating a unordered Map if you want 
        //you can make an array of size 26 for 26 alphabets
        unordered_map<char,int>m;
        //Traversing the s and t and adding every char of s and
        //substracting every char of t.
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        //Now traversing the map and checking if there is any value of char not
        //equal to 0 then return false
        for(auto &it:m){
            if(it.second!=0){
                return false;
            }
        }
        //return the true
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        //we are traversing from index 0 to n-m so that we can have substrings of length m
        //we have divided s2 to substrings of length m and now we will check
            //1. if it is permutation 
                //then we will return true
            //2. if not then check other substring
                //till last if not found any permutation return false
        for(int i=0;i<=n-m;i++){
            string temp=s2.substr(i,m);
            //checking if it is permutation
            if(isPermutation(s1,temp)){
                //if permutation then return true 
                return true;
            }
        }
        //returning the false
        return false;
    }
};