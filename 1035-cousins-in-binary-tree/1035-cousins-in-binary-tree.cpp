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
    unordered_map<int, pair<TreeNode*,int>>mpp;
    void solve(TreeNode* root, TreeNode* parentVal, int depth){
        if(root==NULL){
            return;
        }
        pair<TreeNode*,int> nodeDetail;
        nodeDetail.first = parentVal;
        nodeDetail.second = depth;
        mpp[root->val] = nodeDetail;
        solve(root->left, root, depth+1);
        solve(root->right, root, depth+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL){
            return false;
        }
        solve(root, NULL, 0);
        if ((mpp[x].first != mpp[y].first) && (mpp[x].second == mpp[y].second)){
            return true;
        }
        return false;
    }
};