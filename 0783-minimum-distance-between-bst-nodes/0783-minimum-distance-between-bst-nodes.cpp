class Solution {
public:

    void f(TreeNode* node,vector<int>&arr){
        if(node != NULL){
            arr.push_back(node->val);
            f(node->left,arr);
            f(node->right,arr);
        }
        else{
            return;
        }
    }

    int minDiffInBST(TreeNode* root) {
        vector<int>arr;
        f(root,arr);
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        for(int i = 1;i < arr.size();i++){
            ans = min(ans,arr[i] - arr[i-1]);
        }
        return ans;
    }
};
