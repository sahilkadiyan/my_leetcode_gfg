class Solution {
public:
    int findCenter(vector<vector<int>>& arr) {
        int a = arr[0][0];
        int b = arr[0][1];
        int c = arr[1][0];
        int d = arr[1][1];

        if(a==c || a==d) return a;
        if(b==c || b==d) return b;

        return -1;
    }
};