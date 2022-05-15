class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        double avg=0;
        double sum=0;
        int maximum=*max_element(salary.begin(),salary.end());
        
        int minimum=*min_element(salary.begin(),salary.end());
        for(int i=0;i<n;i++){
            sum=sum+salary[i];
        }
        avg=(sum-maximum-minimum)/(n-2);
        return avg;
    }
};