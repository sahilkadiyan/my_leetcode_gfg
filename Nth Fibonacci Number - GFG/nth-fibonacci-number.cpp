// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
           long long int mem[n+1];
        mem[0]=0,mem[1]=1;
        for(long long int  i=2;i<=n;i++){
            mem[i]=(mem[i-1]+mem[i-2])%1000000007;
        }
        return  mem[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends