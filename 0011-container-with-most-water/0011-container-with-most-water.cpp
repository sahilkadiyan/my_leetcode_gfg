class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //we will have two pointers one is at extreme left and the other one is at the right 
        //now we try to reduce the width of the container 
        
        int left=0;
        int right=height.size()-1;
        
        int maximumArea=0;
        while(left<right){
            
            int area=min(height[left],height[right])*(right-left);
            maximumArea=max(area,maximumArea);
            
            if(height[left]<height[right]) left++;
            else right--;
        }
        
        return maximumArea;
        
        
    }
};