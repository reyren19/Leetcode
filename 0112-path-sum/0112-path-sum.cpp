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
    bool calcSum(TreeNode* root, int sum, int target){
        if(root==NULL){
            return false;
        }
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            return (sum==target);
        }
        bool left = calcSum(root->left, sum, target);
        bool right = calcSum(root->right, sum, target);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
       return calcSum(root, 0, targetSum); 
    }
};