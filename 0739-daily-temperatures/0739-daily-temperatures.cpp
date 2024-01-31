class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // monotonic stack from back
        stack<int>stk;
        int n=temp.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            if(stk.empty()){
                ans[i]=0;
                stk.push(i);
             
            }
            else{
                while(!stk.empty()&&temp[stk.top()]<=temp[i]){
                    stk.pop();
                }
                if(stk.empty()){
                    ans[i]=0;
                }
                else{
                    ans[i]=stk.top()-i;
                    
                }
                stk.push(i);
            }
        }
        return ans;
    }
};