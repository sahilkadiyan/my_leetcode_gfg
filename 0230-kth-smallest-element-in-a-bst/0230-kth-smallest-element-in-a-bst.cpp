class Solution {
public:
    void preOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
        
        //root, left, right 
        v.push_back(root->val);
        preOrderTraversal(root->left, v);
        preOrderTraversal(root->right, v);      
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        preOrderTraversal(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};