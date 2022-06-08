//dp tabulation method
class Solution {
public:
    int tribonacci(int n) {
        //base case
        int mem[n+1];
       
        if (n < 2) 
            return n;
        // if(n==2) return n-1; 
        mem[0]=0,mem[1]=1,mem[2]=1;
        for(int i=3;i<=n;i++){
            mem[i]=mem[i-1]+mem[i-2]+mem[i-3];
        }
        return mem[n];
        
      
    }
};