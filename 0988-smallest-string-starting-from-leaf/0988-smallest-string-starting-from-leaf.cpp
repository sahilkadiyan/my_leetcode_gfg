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
    bool minStr(string s,string t)
    {
        int n= s.size();
        int m=t.size();
        if(n==0) return true;
        int k=min(n,m);
        int minLen=0;
        for(int i=n-1,j=m-1;minLen<k;i--,j--)
    {
        if(t[j]<s[i]) return true;
        else if(t[j]>s[i]) return false;
        minLen++;
    }
    if(n>m) return true;
    return false;
    }
    void smallString(TreeNode* root , string temp,string &SmallestString)
    {
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL)
        {
          temp+=(root->val+'a');
          if(minStr(SmallestString,temp))
          {
              SmallestString=temp;
          }
        }
        temp+=(root->val+'a');
        smallString(root->left,temp,SmallestString);
        smallString(root->right,temp,SmallestString);

    }

    string smallestFromLeaf(TreeNode* root) {
        string temp="",SmallestString="";
        smallString(root,temp,SmallestString);
        int i=0,j=SmallestString.size()-1;
        while(i<j) swap(SmallestString[i++],SmallestString[j--]);
        return SmallestString;
    }
};