class Solution {
public:
   int minEatingSpeed(vector<int>& piles, int h) {
       int l = 0; int r = INT_MAX;
       while(l + 1 < r){
           int m = (l + r) / 2;
           int tmp = 0;
           for(int i = 0; i < piles.size(); i ++){
               tmp += (piles[i]/m + (piles[i]%m != 0));
               if(tmp > h) break; // prevent overflow
           }
           if(tmp <= h) r = m;
           else l = m;
       }
       return r;
   }
};