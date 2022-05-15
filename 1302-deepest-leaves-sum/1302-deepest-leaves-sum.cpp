/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //depth function for calculating the max depth of the binary tree
    int max_depth;
    //this function is for calculating the depth 
    int depth(TreeNode * root){
        if(root==NULL) return 0;
        return max(1+depth(root->left),1+depth(root->right));
    }
    //this is for calculating the sum 
    int sum(TreeNode * root,int depth){
        if(root==NULL) return 0;
        if(depth==max_depth-1) return root->val;
        return sum(root->left,depth+1)+sum(root->right,depth+1);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
       //first of all we need to find out the max depth of the tree so that we can find out the deepest leaves and calculate it's sum 
        
        // so for this we will make a function depth and a sum for calculating the sum 
        //this is for calculating the maximum depth of the binary tree 
        max_depth=depth(root);
        //calling  the function with the depth 0 initially 
        return sum(root,0);
        
        
        
        
    }
};