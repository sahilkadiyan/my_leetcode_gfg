class Solution {
public:
    int countOdds(int low, int high) {
         return (high-low+1)/2+(high%2&&high%2==low%2);
    }
};