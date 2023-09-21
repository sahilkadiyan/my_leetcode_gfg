class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double s;
       
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
         for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        if(v.size()%2==0){
            int mid=v.size()/2;
            s=double(v[mid]+v[mid-1])/2;
        }
     
        if(v.size()%2!=0){
            int mid=v.size()/2;
            s=v[mid];
        }
        return s;
    }
};