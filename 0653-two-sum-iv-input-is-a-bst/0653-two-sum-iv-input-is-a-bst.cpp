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
    void inorder(TreeNode* root,vector<int> &inorde){
        if(root==NULL){
            return ;
        }
        inorder(root->left,inorde);
        inorde.push_back(root->val);
        inorder(root->right,inorde);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorde;
        inorder(root,inorde);
        int n = inorde.size();
        int j = n-1;
        int i=0;
        while(i<j){
            int sum = inorde[i]+inorde[j];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};