/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, vector<TreeNode*> &path, int target){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root->val==target){
            return true;
        }
        if(findPath(root->left, path, target) || findPath(root->right, path, target)){
            return true;
        }     
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*> pPath;
       vector<TreeNode*> qPath; 
       TreeNode* commonNode;
       findPath(root, pPath, p->val);
       findPath(root, qPath, q->val);
        int k=0;
        while(k<pPath.size() && k<qPath.size()){
            if(pPath[k]==qPath[k]){
                commonNode = pPath[k];
            }
            else{
                break;
            }
            k++;
        }
        return commonNode;
    }
};