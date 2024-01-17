class Solution {
public:
    int hIndex(vector<int>& c) {
        // 3 support variables for us
        int s = 0, e = c.size() - 1, avg;
        // the base of every happy binary search ever: having a sorted dataset
        sort(begin(c), end(c));
        // some good old binary search here to find the maximum element meeting the conditions
        while (s <= e) {
            if (c[avg = (e + s) / 2] < c.size() - avg) s = avg + 1;
            else e = avg - 1;
        }
        return c.size() - s;
    }
};