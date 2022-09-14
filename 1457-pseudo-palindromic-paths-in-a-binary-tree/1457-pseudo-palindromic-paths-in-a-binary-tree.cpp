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
   	void pseudoCount(TreeNode*root,vector<int>&v_count,int& count){
    if(root==NULL) return;
    v_count[root->val]++;
    pseudoCount(root->left,v_count,count);
    pseudoCount(root->right,v_count,count);
    
    if(root->left==NULL && root->right==NULL){
        int flag=0;
        for(int i=1;i<=9;i++){
            if(v_count[i]%2!=0){
                flag++;
            }
        }
        if(flag==1||flag==0){
            count++;
        }   
    }
    v_count[root->val]--;
}
int pseudoPalindromicPaths (TreeNode* root) {
    int count=0;
    vector<int> v_count(10,0);
    pseudoCount(root,v_count,count);
    return count;
}
};