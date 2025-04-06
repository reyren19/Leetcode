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
    map<int, vector<pair<int,int>>> mpp;
    void solve(TreeNode* root, int row, int col){
        if(root==NULL){
            return;
        }
        mpp[col].push_back({row,root->val});
        solve(root->left, row+1, col-1);
        solve(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        vector<vector<int>> ans;
        for(auto it: mpp){
            sort(it.second.begin(), it.second.end());
            vector<int> vals;
            for(auto x: it.second){
                vals.push_back(x.second);
            }
            ans.push_back(vals);
        }
        return ans;
    }
};