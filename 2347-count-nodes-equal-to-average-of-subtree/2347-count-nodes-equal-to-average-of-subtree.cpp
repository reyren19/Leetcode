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
    int count = 0;
    int countNodes(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int leftCnt = countNodes(node->left); 
        int rightCnt = countNodes(node->right);
        int totalCnt = leftCnt+rightCnt+1;
        return totalCnt;       
    }
    int subtreeSum(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int leftSum = subtreeSum(node->left);
        int rightSum = subtreeSum(node->right);
        int totalSum = leftSum+rightSum+node->val;
        return totalSum;
    }
    int averageOfSubtree(TreeNode* root) {
       if(root==NULL){
        return 0;
       }
        int sum = subtreeSum(root);
        int cnt = countNodes(root);
        if(cnt!=0){
            if(sum/cnt==root->val){
                count++;
            }
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
       return count;
    }
};