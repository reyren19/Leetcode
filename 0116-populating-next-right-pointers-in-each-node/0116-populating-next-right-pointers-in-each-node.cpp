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
    // using no queue approach and solving like linked list
        if(root==NULL){
            return NULL;
        }
        Node* leftMost = root;
        // this tells us that we reached leaf
        while(leftMost->left!=NULL){
            Node* currNode = leftMost;
            // traversing level
            while(currNode!=NULL){
                currNode->left->next = currNode->right;
                // connecting bridge
                if(currNode->next!=NULL){
                    currNode->right->next = currNode->next->left;
                }
                currNode=currNode->next;
            }
            leftMost = leftMost->left;
        }
        return root;
    }
};

/* LEVEL ORDER APPROACH-
      Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            Node* prev = NULL;
            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();
                if (prev != NULL) {
                    prev->next = node;
                }
                prev = node;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            prev->next = NULL;
        }
        return root;
    }

 */