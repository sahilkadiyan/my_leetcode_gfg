class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> s; // pair : (index, height)

        for (int i = 0; i < heights.size(); ++i) {
            int start = i;
            while (!s.empty() && s.top().second > heights[i]) {
                int index = s.top().first;
                int height = s.top().second;
                s.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            s.push(make_pair(start, heights[i]));
        }

        while (!s.empty()) {
            int index = s.top().first;
            int height = s.top().second;
            s.pop();
            maxArea = max(maxArea, height * (int)(heights.size() - index));
        }
        return maxArea;
    }
};