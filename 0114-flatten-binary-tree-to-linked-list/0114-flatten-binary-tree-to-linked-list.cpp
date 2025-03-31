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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        // store root's right in a var
        TreeNode* node = root->right;
        //bring root's left to the right
        root->right = root->left;
        root->left = NULL;
        TreeNode* temp = root;
        while(temp->right){
            temp=temp->right;
        }
        // add the right to the rightmost part
        temp->right = node;
        // call the function for the next node in line i.e. right node
        flatten(root->right);
    }
};