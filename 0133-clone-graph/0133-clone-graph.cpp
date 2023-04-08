class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        
        queue<Node*> que;
        que.push(node);
        
        while (!que.empty()) {
            Node* curr = que.front();
            que.pop();
            
            for (auto neighbor : curr->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    que.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        
        return visited[node];
    }
};