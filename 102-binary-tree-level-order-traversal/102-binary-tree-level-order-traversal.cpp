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
#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        vector<int> level;
    if(root != NULL){
        
        q.push(root);
        level.push_back(root->val);
        res.push_back(level);
        level.clear();
        
        while(!q.empty()){
            int i, n;
            for(i = 0, n = q.size(); i < n; i++){
                TreeNode* p = q.front();
                q.pop();
                
                if(p -> left != NULL){
                    q.push(p->left);
                    level.push_back(p->left->val);
                }
                if(p-> right != NULL){
                    q.push(p->right);
                    level.push_back(p->right->val);
                }
            }
                if(!level.empty() && i == n){
                    res.push_back(level);
                    level.clear();
                }
        }
    }
     return res;
    }
};