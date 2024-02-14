class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();
                if((s[i]==')' && ch=='(') or (s[i]==']' && ch=='[') or (s[i]=='}' && ch=='{')) continue;
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
        
    }
};