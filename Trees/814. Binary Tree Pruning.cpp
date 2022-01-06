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
    
    bool dfs(TreeNode *root)
    {
        if(root==NULL)  return true;
        bool left=dfs(root->left);
        bool right=dfs(root->right);
        if(root->left && left==true)
        {
            root->left=NULL;
        }
        
        if(root->right && right==true)
        {
            root->right=NULL;
        }
        
        return (left && right && root->val==0);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool flag=dfs(root);
        if(flag)
        {
            root=NULL;
        }
        return root;
    }
};