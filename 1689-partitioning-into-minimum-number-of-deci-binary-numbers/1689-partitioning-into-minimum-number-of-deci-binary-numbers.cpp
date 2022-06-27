class Solution {
public:
    int minPartitions(string n) {
        
        
          int maxDigit=INT_MIN;
        
        for(int i=0; i< n.length(); i++)
            maxDigit = max(maxDigit, n[i]-'0');
    
        return maxDigit;
    }
};