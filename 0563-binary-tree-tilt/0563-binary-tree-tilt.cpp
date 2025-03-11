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
    int totalTilt = 0;
    int solve(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int lSum = solve(node->left);
        int rSum = solve(node->right);
        totalTilt += abs(lSum-rSum);
        return node->val + lSum + rSum;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        solve(root);
        return totalTilt;
    }
};