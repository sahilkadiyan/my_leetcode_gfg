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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> traversal;
        queue<pair<TreeNode *, int>> q;
        q.push({root,0});
        TreeNode *node;
        int level;
        while(!q.empty()) {
            node = q.front().first;
            level = q.front().second;
            q.pop();
            if (traversal.size() <= level) 
                traversal.push_back(vector<int>());
            traversal[level].push_back(node->val);
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        
        for (int k = 1; k < traversal.size(); k += 2) {
            reverse(traversal[k].begin(), traversal[k].end());
        }
        return traversal;
    }
};