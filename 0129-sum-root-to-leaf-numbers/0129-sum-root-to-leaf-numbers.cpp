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
    void solve(TreeNode* root, int &sum, string num){
        if(root==NULL){
            return;
        }
        num += root->val + '0';
        if(root->left==NULL && root->right==NULL){
            sum += stoi(num);
            return;
        }
        solve(root->left, sum, num);
        solve(root->right, sum, num);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        string num = "";
        int sum = 0;
        solve(root, sum,num);
        return sum;
    }
};