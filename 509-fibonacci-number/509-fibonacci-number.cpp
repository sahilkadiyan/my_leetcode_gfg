//this question can be done in 3 ways:
//1: recursion  2: memoization  3: tabulation method
//this one is the tabulation method tabulation is a bottom up appraoch in which we know the result of the previous term and with the help of that we can compute the next term easily 
//here we know the 1st two terms of fibonacci series i.e 0 and 1 so with the help of these two numbers we can easily compute the next term 
class Solution {
public:
    int fib(int n) {
        vector<int> v(n+2);
     // v.push_back(0);
     //    v.push_back(1);
  v[0]=0;
        v[1]=1;
        for(int i=2;i<=n;i++){
            v[i]=(v[i-1]+v[i-2]);
        }
        return v[n];
       
    }
};