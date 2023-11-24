class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        deque<int> queue;
        for (int num : piles) {
            queue.push_back(num);
        }
        
        int ans = 0;
        while (!queue.empty()) {
            queue.pop_back(); // alice
            ans += queue.back(); // us
            queue.pop_back();
            queue.pop_front(); // bob
        }
        
        return ans;
    }
};