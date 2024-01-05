class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m=left,n=right;
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};