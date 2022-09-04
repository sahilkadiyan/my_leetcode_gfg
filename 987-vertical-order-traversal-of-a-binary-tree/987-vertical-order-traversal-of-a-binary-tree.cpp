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
    void dfs(TreeNode* root, int col, int row, map<int, map<int, multiset<int>>>& nodes) {
        // if root is nullptr, then skip it
        if (!root) return;
         
        // insert the current node value to corresponding row and grouped by col.
        // see above diagram for better understanding
        // for example, 
        // we add node 1 to nodes[0][0]
        // we add node 5 to nodes[0][2]. 
        // we add node 6 to nodes[0][2]
        nodes[col][row].insert(root -> val);
         
        // then we perform pre order traversal
        // see https://wingkwong.github.io/leetcode-the-hard-way/tutorials/graph-theory/binary-tree#pre-order
        // for more understanding on tree traversals
        // dfs on left sub tree
        dfs(root-> left, col - 1, row + 1, nodes);
        // dfs on right sub tree
        dfs(root-> right, col + 1, row + 1, nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // init ans - store the final ans
        vector<vector<int>> ans;
        // nodes is used to store the node values grouped by column 
        // see above diagram for better understanding
        // use multiset here as the value could be same
        // use map here to take care of the order
        map<int, map<int, multiset<int>>> nodes;
        // dfs starting from the root of the tree
        dfs(root, 0, 0, nodes);
        // for each column in nodes
        for (auto column : nodes) {
            // init col - store the node values for all rows at the current column 
            vector<int> col;
            // for each row at the current column, we append all the node values to col
            // for example: column idx = 0, we add row = 0 (node 1) and row = 2 (node 5 & node 6)
            for (auto rows : column.second) {
                // we can use `insert` to add all elelments to a vector
                // instead of adding them one by one
                col.insert(col.end(), rows.second.begin(), rows.second.end());
            }
            // we've processed this col, add it to ans
            ans.push_back(col);
        }
        // return final ans
        return ans;
    }
};