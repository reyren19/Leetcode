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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0; // keep track of root
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root= buildTree(preorder, inorder, preIndex, 0, inorder.size()-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd){
        if(inStart>inEnd){
            return NULL;
        }
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = mpp[rootVal];
        root->left = buildTree(preorder, inorder, preIndex, inStart, rootIndex-1);
        root->right = buildTree(preorder, inorder, preIndex, rootIndex+1, inEnd);
        return root;
    }
};