class Solution {
public:
    struct myCmp{
        bool operator()(string a, string b){
            if(a.size() == b.size())
            {
                return a < b;
            }
            
            return a.size() < b.size();
        }    
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, myCmp> pq;
        for(string s : nums)
            pq.push(s);
        
        string ans;
        while(k>0)
        {
            if(k == 1)
            {
                ans = pq.top();
            }
            pq.pop();
            k--;
        }
        return ans;
    }
};