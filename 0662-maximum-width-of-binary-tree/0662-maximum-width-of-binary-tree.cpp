class Solution {
public:
int widthOfBinaryTree(TreeNode* root) {
queue<pair<TreeNode*, int> >pq;
int ans = 0;
pq.push({root,0});
while(!pq.empty()){
int size = pq.size();
int st = pq.front().second;
int end = pq.back().second;
ans = max(ans,end-st+1);

        for(int i =0;i<size;i++){
           TreeNode* temp = pq.front().first;
            int num = pq.front().second;
           pq.pop();
          
           if(temp->left != NULL) pq.push({temp->left,(long long )2*num+1});
           if(temp->right != NULL) pq.push({temp->right,(long long )2*num+2});
        }
       
    }
    return ans;
}
};