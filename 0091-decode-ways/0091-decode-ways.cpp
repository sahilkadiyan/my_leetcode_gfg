class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
	
    vector<int> dp(n+1,0);
    dp[0]=1;  // if string is empty there is  1 way to decode it i.e string is empty
    if(s[0]!='0')
        dp[1]=1; //if the first digit is 0(zero) then there is no way to decode it as invisually or combined with other digit as (06 !=6)
    for(int i=2;i<=n;i++)
    {
        int op1=(s[i-1]-'0');
        int op2=(s[i-2]-'0')*10+(s[i-1]-'0');
        
        if(op1>=1)
            dp[i]+=dp[i-1];
        if(op2>=10&&op2<=26)
            dp[i]+=dp[i-2];   
    }
    return dp[n];
    }
};