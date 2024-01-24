class Solution {
public:
    int solve(TreeNode* root, int count ) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = solve(root->left, count) + solve(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root,0);
        
    }
};