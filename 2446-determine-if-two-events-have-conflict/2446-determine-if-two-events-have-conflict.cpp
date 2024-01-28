class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        return e1[0] <= e2[1] && e2[0] <= e1[1];
    }
};