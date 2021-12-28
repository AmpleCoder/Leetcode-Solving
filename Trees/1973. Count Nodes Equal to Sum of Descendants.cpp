/*
simple problem here we only need to compare the sum of values of left and right subtrees with the current nodes value 
*/

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
    
    long dfs(TreeNode *root,int &ans)
    {
        if(root==NULL)  return 0;
        long left=dfs(root->left,ans);
        long right=dfs(root->right,ans);
        if(left==root->val-right)
        {
            ans++;
        }
        
        return left+right+root->val;
    }
    
    int equalToDescendants(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};