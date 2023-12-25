class Solution {
    int cam = 0;
    public int minCameraCover(TreeNode root) {
        // (0) -> cam + 1 ,(1,2) --> cam
        return dfs(root)==0 ? cam+1 : cam;
    }
    
    // 2 --> Has Camera
    // 1 -> Covered with the camera
    // 0 --> No camera is covering this node
    public int dfs(TreeNode node) {
        if(node == null) return 1;
        int left = dfs(node.left);
        int right = dfs(node.right);
        //Check if we need to add a camera
        if(left == 0 || right == 0) {
            cam++;
            return 2;
        }
        else if(left == 2 || right == 2) return 1;
        else return 0;
        
    }
}