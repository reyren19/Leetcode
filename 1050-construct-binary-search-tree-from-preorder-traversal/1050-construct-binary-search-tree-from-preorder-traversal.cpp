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
    int idx = 0;
    // using the check bst method 
    TreeNode* buildTree(vector<int> preorder, int min, int max){
        if(idx>=preorder.size() || preorder[idx]<min || preorder[idx]>max){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = buildTree(preorder, min, root->val);
        root->right = buildTree(preorder, root->val, max);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, INT_MIN, INT_MAX);
    }
};