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
    void swapNodes(TreeNode* &root1 , TreeNode* &root2){
        TreeNode* newNode = new TreeNode();
        newNode=root1;
        root1=root2;
        root2=newNode;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        swapNodes(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};