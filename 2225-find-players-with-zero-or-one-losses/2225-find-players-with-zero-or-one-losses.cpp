class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer(2);
        
        unordered_map<int, int> countLose;
        
        for(vector<int> &match : matches) {
            countLose[match[1]]++;
            countLose[match[0]] += 0;
        }
        
        for(auto &p: countLose) {
            if(p.second == 0) {
                answer[0].push_back(p.first);
            } else if(p.second == 1) {
                answer[1].push_back(p.first);
            }
        }
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};