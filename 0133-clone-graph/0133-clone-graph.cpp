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
    Node* dfs(Node* node, unordered_map<Node*, Node*> &m){
        //Base: Create a clone node with same value and empty neighbours 
        Node* newNode=new Node(node->val);
        m[node]=newNode;

        //Traverse to all neighbours of node, if node present in alias map append neighbours 
        //Else call dfs recursively if node not in map and then append neighbours

        for(auto nbr: node->neighbors){
            if(m.find(nbr)==m.end()){
                newNode->neighbors.push_back(dfs(nbr,m));
            }else{
                newNode->neighbors.push_back(m[nbr]);
            }
        }

        return newNode;

    }

    Node* cloneGraph(Node* node) {
        //Alias node lookup map, Key original node, value clone node
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*> m;
        return dfs(node,m);
    }
};