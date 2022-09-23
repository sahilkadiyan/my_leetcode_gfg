class Solution {
public:
    int concatenatedBinary(int n) {
       // `l` is the bit length to be shifted
        int M = 1e9 + 7, l = 0;
        // use long here as it potentially could overflow for int
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            // i & (i - 1) means removing the rightmost set bit
            // e.g. 100100 -> 100000
            //      000001 -> 000000
            //      000000 -> 000000
            // after removal, if it is 0, then it means it is power of 2
            // as all power of 2 only contains 1 set bit
            // if it is power of 2, we increase the bit length `l`
            if ((i & (i - 1)) == 0) l += 1;
            // (ans << l) means shifting the orginal answer `l` bits to th left
            // (x | i) means  using OR operation to set the bit
            // e.g. 0001 << 3 = 0001000
            // e.g. 0001000 | 0001111 = 0001111
            ans = ((ans << l) | i) % M;
        }
        return ans;  
    }
};