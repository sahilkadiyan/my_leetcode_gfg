#include<stack>
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans=0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<s.length();i++){
          
            int x=st.top();
            if(x!=-1 && s[i]==')' && s[x]=='('){
                st.pop();
                ans=max(ans,i-st.top());
            }
            else{
                st.push(i);
            }
          
        }
        return ans;
        
    }
};