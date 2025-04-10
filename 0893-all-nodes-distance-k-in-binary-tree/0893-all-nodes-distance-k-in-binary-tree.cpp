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
    /* 
        steps for my approach=
        make a map<Node*, pair<int,bool>> bool being if it is same direction as target node and int being dist from node
        populate the map 
        now iterate over the map and check-
        if(same side as target){
            diff = abs(targetDiff-it.second.first);
            if(diff == k){
                vec.add(it.first)
            }
        } 
        else{
            diff = abs(targetDiff+it.second.first);
            if(diff == k){
                vec.add(it.first)
            }
        }
        return vec;
    */
    void findParents(unordered_map<TreeNode*, TreeNode*> &mpp, TreeNode* root){
        if(root==NULL){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left != NULL){
                mpp[current->left]=current;
                q.push(current->left);
            }
            if(current->right != NULL){
                mpp[current->right]=current;
                q.push(current->right);
            }            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track; // {node -> parent}
    findParents(parent_track, root);  
    unordered_map<TreeNode*, bool> visited;
    vector<int> ans;
    queue<TreeNode*> q;
    if(root == NULL || target == NULL){
        return ans;
    }
    q.push(target);
    visited[target] = true;
    int currLevel = 0;
    
    while(!q.empty()){
        int levelSize = q.size();
        if(currLevel == k) break;
        for (int i = 0; i < levelSize; i++){
            TreeNode* current = q.front();
            q.pop();
            
            if(current->left && !visited[current->left]){
                visited[current->left] = true;
                q.push(current->left);
            }
            if(current->right && !visited[current->right]){
                visited[current->right] = true;
                q.push(current->right);
            } 
            if(parent_track[current] && !visited[parent_track[current]]){
                visited[parent_track[current]] = true;
                q.push(parent_track[current]);
            }
        }
        currLevel++;
    }
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        ans.push_back(curr->val);
    }
    return ans;
}

};