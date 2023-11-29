#include <queue>
using namespace std;
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
           const int level_size = queue.size();
           Node* prev_node = nullptr;
           Node* current_node = nullptr;
           for (int i = 0; i < level_size; ++i) {
                current_node = queue.front();
                queue.pop();
                if (prev_node) prev_node -> next = current_node;
                if (current_node -> left) queue.push(current_node -> left);
                if (current_node -> right) queue.push(current_node -> right);
                prev_node = current_node;
           }
           current_node -> next = nullptr;
        }
        return root;
    }
};

