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

/*
if lca is source node then only up up (L,R) traversal
if lca is destination node then only U traversal 
otherwise source to lca U traversals from lca to destination (L,R) traversal
*/

/*
giving tle need to optimise it vmro
*/

class Solution {
public:
    
    TreeNode *lowestCommonAncestor(TreeNode *root,int startValue,int destValue)
    {
        if(root==NULL)  
        {
            return NULL;
        }
        
        if(root->val==startValue || root->val==destValue)
        {
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left,startValue,destValue);
        TreeNode *right = lowestCommonAncestor(root->right,startValue,destValue);
        
        if(left!=NULL && right!=NULL)
        {
            return root;
        }
        
        if(left!=NULL)
        {
            return left;
        }
        
        return  right;
    }
    
    string dfs(TreeNode *root,int val,string str="")
    {   
        if(root==NULL)  return "";
        if(root->val==val)  return str;
        str.push_back('L');
        string left=dfs(root->left,val,str);
        if(left!="")    return left;
        str.pop_back();
        str.push_back('R');
        string right=dfs(root->right,val,str);
        return right;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca=lowestCommonAncestor(root,startValue,destValue);
        string up,down;
        down=dfs(lca,destValue);
        up=dfs(lca,startValue);
        int size=up.size(),i;
        // cout<<up<<" "<<down;
        for(i=0;i<size;i++)
        {
            up[i]='U';
        }
        
        if(lca->val==startValue)
        {
            return down;
        }
        
        if(lca->val==destValue)
        {
            return up;
        }
        
        up+=down;
        return up;
        
        
    }
};