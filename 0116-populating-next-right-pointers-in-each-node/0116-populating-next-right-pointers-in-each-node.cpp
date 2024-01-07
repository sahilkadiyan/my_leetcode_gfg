/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
            if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(size(q)) {
            Node* rightNode = nullptr;                    // set rightNode to null initially
            for(int i = size(q); i; i--) {                // traversing each level
                auto cur = q.front(); q.pop();            // pop a node from current level and,
                cur -> next = rightNode;                  // set its next pointer to rightNode
                rightNode = cur;                          // update rightNode as cur for next iteration
                if(cur -> right)                          // if a child exists
                    q.push(cur -> right),                 // IMP: push right first to do right-to-left BFS
                    q.push(cur -> left);                  // then push left
            }
        }
        return root;
        
    }
};