/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node *n = new Node();
        helper(n, grid, 0, grid.size(), 0, grid.size());
        return n;
    }

    void helper(Node *node, vector<vector<int>>& grid, int m1, int m2, int n1, int n2) {
        // Perform loop
        for (int i = m1; i < m2; i++) {
            for (int j = n1; j < n2; j++) {
                if (grid[i][j] != grid[m1][n1]) {
                    Node *newnode;
                    
                    newnode = new Node(0, false);
                    helper(newnode, grid, m1, (m1 + m2)/2, n1, (n1 + n2)/2);
                    node->topLeft = newnode;
                    
                    newnode = new Node(0, false);
                    helper(newnode, grid, m1, (m1 + m2)/2, (n1 + n2)/2, n2);
                    node->topRight = newnode;
                    
                    newnode = new Node(0, false);
                    helper(newnode, grid, (m1 + m2)/2, m2, n1, (n1 + n2)/2);
                    node->bottomLeft = newnode;
                    
                    newnode = new Node(0, false);
                    helper(newnode, grid, (m1 + m2)/2, m2, (n1 + n2)/2, n2);
                    node->bottomRight = newnode;
                    return;
                }
            }
        }
        node->isLeaf = true;
        node->val = grid[m1][n1];
        return;
    }
};