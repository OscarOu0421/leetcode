/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Hash map to store the mapping from original node to its cloned counterpart
    unordered_map<Node*, Node*> map;

    /*
        DFS function to clone the graph.
        - If the node has not been cloned, create a new node.
        - Recursively clone all its neighbors and store them in the new node's neighbor list.

        Time Complexity: O(V + E) 
          - Each node (V) is visited once.
          - Each edge (E) is traversed once during DFS.
        
        Space Complexity: O(V) 
          - Hash map stores one entry per node.
          - Recursive call stack can go up to O(V) deep in the worst case.
    */
    Node *dfs(Node *node) {
        // Clone the current node and store it in the map
        map[node] = new Node(node->val);

        // Iterate through all the neighbors
        for (auto neighbor : node->neighbors) {
            // If the neighbor is not yet cloned, recursively clone it
            if (map.find(neighbor) == map.end()) {
                map[node]->neighbors.push_back(dfs(neighbor));
            } else {
                // If already cloned, directly add the reference to the new node's neighbors
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
        return map[node]; // Return the cloned node
    }

    /*
        Main function to clone the entire graph.
        - Returns NULL if the input graph is empty.
        - Calls DFS to perform a deep copy of the graph.

        Time Complexity: O(V + E) - Same reasoning as dfs().
        Space Complexity: O(V) - Hash map stores cloned nodes.
    */
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        return dfs(node);
    }
};
