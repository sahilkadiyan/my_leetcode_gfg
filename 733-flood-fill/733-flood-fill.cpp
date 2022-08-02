class Solution {
public:
    //this can be solved using DFS
    //here c0 is the intial color and c1 is the newcolor
    
    void dfs(vector<vector<int>>& image,int i,int j,int c0,int c1){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=c0 ) return ;
        image[i][j]=c1; //set that index to new color
        
        //calling function for all the 4-directionally connected pixels
        dfs(image,i,j-1,c0,c1);
        dfs(image,i,j+1,c0,c1);
        dfs(image,i-1,j,c0,c1);
        dfs(image,i+1,j,c0,c1);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]!=color)
            dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};