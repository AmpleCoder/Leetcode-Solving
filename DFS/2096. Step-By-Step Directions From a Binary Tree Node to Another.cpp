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

//solution 1
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
    
    bool dfs(TreeNode *root,int val,string &str)
    {   
        if(root==NULL)  return false;
        if(root->val==val)  return true;
        str.push_back('L');
        bool left=dfs(root->left,val,str);
        if(left)    return true;
        str.pop_back();
        str.push_back('R');
        bool right=dfs(root->right,val,str);
        if(right)   return true;
        str.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca=lowestCommonAncestor(root,startValue,destValue);
        string up,down;
        dfs(lca,destValue,down);
        dfs(lca,startValue,up);
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

//solution 2
/*
it uses the fact that first we find out the path from root to startValue 
then we find the path from root to destValue
and after that we remove the common prefix to get the result
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

/*
if lca is source node then only up up (L,R) traversal
if lca is destination node then only U traversal 
otherwise source to lca U traversals from lca to destination (L,R) traversal
*/

class Solution {
public:
    
    bool find(TreeNode *root,int val,string &path)
    {
        if(root->val==val)  return true;
        if(root->left && find(root->left,val,path))
        {
            path.push_back('L');
        }
        
        else if(root->right && find(root->right,val,path))
        {
            path.push_back('R');
        }
        
        return !path.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string up,down;
        find(root,startValue,up);
        find(root,destValue,down);
        // cout<<up<<" "<<down;
        while(!up.empty() && !down.empty() && up.back() == down.back())
        {
            up.pop_back();
            down.pop_back();
        }
        
        return string(up.size(),'U')+string(rbegin(down),rend(down));
    }
};