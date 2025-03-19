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
    unordered_map<int,int> mpp;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        int nodeVal = root->val;
        mpp[nodeVal]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> v;
        int maxCnt = 0;
        solve(root);
        for(auto it: mpp){
            if(it.second >= maxCnt){
                maxCnt = it.second;
            }
        }
        for(auto it: mpp){
            if(it.second==maxCnt){
                v.push_back(it.first);
            }
        }
        return v;
    }
};