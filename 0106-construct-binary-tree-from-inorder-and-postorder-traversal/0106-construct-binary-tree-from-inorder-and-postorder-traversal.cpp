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
    TreeNode* buildTreeRecursive(vector<int> &postorder,vector<int> &inorder,int poststart,int postend,int instart,int inend){
        if(poststart>postend){
            return NULL;
        }
        int rootdata=postorder[postend];
        int lpoststart=poststart;
        int lpostend;
        int linstart=instart;
        int linend;
        int rpoststart;
        int rpostend=postend-1;
        int rinstart;
        int rinend=inend;
        for(int i=instart;i<=inend;i++){
            if(inorder[i]==rootdata){
                linend=i-1;
                rinstart=i+1;
                lpostend=linend+lpoststart-linstart;
                rpoststart=lpostend+1;
                break;
            }
        }
        TreeNode* root=new TreeNode(rootdata);
        TreeNode *leftsubtree=buildTreeRecursive(postorder,inorder,lpoststart,lpostend,linstart,linend);
        TreeNode* rightsubtree=buildTreeRecursive(postorder,inorder,rpoststart,rpostend,rinstart,rinend);
        root->left=leftsubtree;
        root->right=rightsubtree;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inlength=inorder.size();
        int postlength=postorder.size();
        return buildTreeRecursive(postorder,inorder,0,postlength-1,0,inlength-1);
        
    }
};