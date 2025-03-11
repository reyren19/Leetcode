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
    bool solve(TreeNode* root, int currSum, int targetSum, vector<vector<int>> &v, vector<int> curr){
        if(root==NULL){
            return false;
        }
        currSum += root->val;
        curr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(currSum==targetSum){
                v.push_back(curr);
                return true;
            }
            else{
                return false;
            }
        }
        bool left = solve(root->left, currSum, targetSum,v,curr);
        bool right = solve(root->right, currSum, targetSum,v,curr);
        return left||right;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        vector<int> curr;
        solve(root, 0, targetSum,v,curr);
        return v;
    }
};