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
    
    TreeNode *lca(TreeNode *root,int p,int q)
    {
        if(root==NULL)  return root;
        if(root->val==p || root->val==q)    return root;
        TreeNode *left=lca(root->left,p,q);
        TreeNode *right=lca(root->right,p,q);
        if(left && right)   return root;
        if(left)    return left;
        return right;
    }
    
    void dfs(TreeNode *root,int val,int level,int &ans)
    {
        if(root==NULL)  return;
        
        if(root->val==val)
        {
            ans=level;
            return;
        }
        
        dfs(root->left,val,level+1,ans);
        dfs(root->right,val,level+1,ans);
    }
    
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode *lc=lca(root,p,q);
        int d1,d2;
        d1=d2=0;
        dfs(lc,p,0,d1);
        dfs(lc,q,0,d2);
        return d1+d2;
    }
};

/*
follow up :- how to do it in one pass
*/