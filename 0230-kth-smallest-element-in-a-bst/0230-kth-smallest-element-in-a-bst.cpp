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

// BRUTE= STORE ROOTS IN A VECTOR, SORT IT AND RETURN KTH ELEMENT 
class Solution {
public:
    void solve(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        solve(root->left, v);
        v.push_back(root->val);        
        solve(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        solve(root,v);
        return v[k-1];
    }
};