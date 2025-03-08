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
    int count = 0;
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int totalSum = left.first+right.first+root->val;
        int totalCount = left.second+right.second+1;
        int average = totalSum/totalCount;
        if(average==root->val){
            count++;
        }
        return {totalSum,totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};