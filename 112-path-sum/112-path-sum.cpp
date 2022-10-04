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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false; 
        if(!(root->left) && !(root->right) && !(targetSum-(root->val))) return true;
        bool left=false, right=false; 
        if(root->left) left = hasPathSum(root->left,targetSum-(root->val)); 
        if(root->right) right = hasPathSum(root->right,targetSum-(root->val));
        return left or right;  
    }
};