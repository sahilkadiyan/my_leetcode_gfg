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
   void dfs(TreeNode* root, vector<string> &ans, string path){
    path += (path.size()?"->":"") + to_string(root->val);
    if(!root->left && !root->right) ans.push_back(path);
    if(root->left)  dfs(root->left, ans, path);
    if(root->right) dfs(root->right, ans, path);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string path = "";
    dfs(root, ans, path);
    return ans;
}
};