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
    string tree2str(TreeNode* root) {
                if (!root) return "";
        // we convert root->val to string here, then append results from different cases
        string s = to_string(root->val);
        // handle case 2
        // this line is obviously not necessary
        if (!root->left && !root->right) s += "";  
        // handle case 3
        if (root->left) s += "(" + tree2str(root->left) + ")";
        // handle case 4
        // alternatively, you can use `else if (root->right) s += "()";`
        if (!root->left && root->right) s += "()";
        // handle case 5
        if (root->right) s += "(" + tree2str(root->right) + ")";
        return s;

    }
};