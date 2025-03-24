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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag = false;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> level;
            for(int i=0; i<lvlSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            flag = !flag;
            if(flag==true){
            ans.push_back(level);
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
        }
        return ans;
    }
};