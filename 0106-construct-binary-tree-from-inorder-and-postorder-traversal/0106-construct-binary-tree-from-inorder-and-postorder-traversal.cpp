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
    unordered_map<int,int> mp;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int postStart, int postEnd, int inStart, int inEnd) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[postorder[postEnd]];
        int numsRight = inEnd - inRoot;
        
        root -> left = helper(inorder, postorder, postStart, postEnd - numsRight - 1, inStart, inRoot - 1);
        root -> right = helper(inorder, postorder, postEnd - numsRight, postEnd - 1, inRoot + 1, inEnd);
        

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
};