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
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // node found
            // case 1- either left and right or both not present
            if(!root->left){
                TreeNode* rightNode = root->right;
                delete(root);
                return rightNode;
            }
            else if(!root->right){
                TreeNode* leftChild = root->left;
                delete(root);
                return leftChild;
            }
            else{
                TreeNode* rightNode = root->right;
                TreeNode* leftNode = root->left;
                delete(root);
                TreeNode* minRightNode = findMin(rightNode);
                minRightNode->left = leftNode;
                return rightNode;
            }
        }
        return root;
    }
};