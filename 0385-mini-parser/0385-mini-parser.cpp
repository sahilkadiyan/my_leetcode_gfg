class Solution {
public:
    NestedInteger deserialize(string s) {
        function<bool(char)> isnumber = [](char c){ return (c == '-') || isdigit(c); };
        
        stack<NestedInteger> stk;
        stk.push(NestedInteger());
        
        for (auto it = s.begin(); it != s.end();) {
            const char & c = (*it);
            if (isnumber(c)) {
                auto it2 = find_if_not(it, s.end(), isnumber);
                int val = stoi(string(it, it2));
                stk.top().add(NestedInteger(val));
                it = it2;
            }
            else {
                if (c == '[') {
                    stk.push(NestedInteger());
                }
                else if (c == ']') {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
                ++it;
            }
        }
        
        NestedInteger result = stk.top().getList().front();
        return result;
    }
};