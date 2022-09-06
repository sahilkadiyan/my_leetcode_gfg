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
    TreeNode* pruneTree(TreeNode* root) {
        return containsone(root)? root:NULL;
    }
    
    bool containsone(TreeNode * root){
        if(root==NULL) return false;
        bool leftcontainsone=containsone(root->left);
        bool rightcontainsone=containsone(root->right);
        if(!leftcontainsone) root->left=NULL;
        if(!rightcontainsone) root->right=NULL;
        return root->val==1 || leftcontainsone || rightcontainsone;
        
        
        
    }
};