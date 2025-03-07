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
    int ans;
    int dfs(TreeNode* root, int parentVal){
        if(root==NULL){
            return 0;
        }
        int left = dfs(root->left, root->val);
        int right = dfs(root->right, root->val);
        // compute ans after reaching leaves and returning
        ans = max(ans, left+right);
        // checking if current node is equal to the parent node value
        if(root->val == parentVal){
            // max height to the upper node
            return max(left,right)+1;
        }
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        // passing -1 so that root does not get included in the chain
        dfs(root, -1);
        return ans;
    }
};