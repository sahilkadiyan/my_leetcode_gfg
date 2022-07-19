class Solution {
public:
    //here we need to remember that at 0th stair we can take 1 step i.e for n==1 that's why we take prev2=1 
    //space : o(1)
    //time : o(n)
    
    int climbStairs(int n) {
        
        int prev2=1;  //The base case will be when we want to go to the 0th stair, then we have only one option.
        
        int prev=1;
        
        for(int i=2;i<=n;i++){
            int curri=(prev+prev2);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};