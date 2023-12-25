class Solution {
    int cam;
    Set<TreeNode> covered;
    public int minCameraCover(TreeNode root) {
        if(root == null) return 0;
        cam = 0;
        covered = new HashSet<>();
        covered.add(null); // Skip the leaf nodes and start from one level above.
        dfs(root, null);
        return cam;
    }
    
    public void dfs(TreeNode node, TreeNode parent){
        if(node != null) {
            dfs(node.left, node);
            dfs(node.right, node);
            
            //Check if i need to add camera at node. 
            // Parent is null & node is uncovered 
            // OR 
            // if any of its left or right child are not covered
            
            if(parent == null && !covered.contains(node)
               || !covered.contains(node.left) || !covered.contains(node.right)) {
                cam++;
                covered.add(node);
                covered.add(parent);
                covered.add(node.left);
                covered.add(node.right);
            }
            
        }
    }
}
