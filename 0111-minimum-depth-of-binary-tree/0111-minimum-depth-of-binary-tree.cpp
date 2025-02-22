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
    int minDepth(TreeNode* root) {
        int lvl=0;
        unordered_map<int,int>mpp;
        if(!root){
            return 0;
        }
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            lvl++;
            for(int i=0; i<levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left && !node->right){
                    return lvl;
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
        }
        return lvl;
    }
};