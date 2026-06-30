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
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> referenceMap;
        return addNode(node, referenceMap);
    }

    Node* addNode(Node* node,unordered_map<int, Node*>& referenceMap) {
        if(node == NULL) {
            return NULL;
        }
        if(referenceMap.contains(node->val)) {
            return referenceMap[node->val];
        }
        Node* newNode = new Node(node->val);
        referenceMap[node->val] = newNode;
        vector<Node*> newNeighbors;
        for(Node* n:node->neighbors) {
            newNeighbors.push_back(addNode(n, referenceMap));
        }
        newNode->neighbors = newNeighbors;
        return newNode;
    }
};
