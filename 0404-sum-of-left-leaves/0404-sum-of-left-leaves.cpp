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
    int sum = 0;
    void calculate(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left != NULL && root->left->left==NULL && root->left->right==NULL){
            sum+=root->left->val;
        }        
        calculate(root->left);
        calculate(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        calculate(root);
        return sum;
    }
};