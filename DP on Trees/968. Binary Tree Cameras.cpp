/*
here we can do 3 things to a particular node
a)either we can set camera at the current node
b)either the current node is already covered(monitored by some of it's neighbour)
c)either the current node requires camera

so we can assign some value to these three variables(HasCamera,Covered,PleaseCover)
and first we can fetch the status which we are getting from left and right subtree
now suppose value of left = l and right = r
if(both left and right subtree needs camera)
{
    we should install camera at current node and return status covered to parent (as current node will take care of its parent)
    and increment number of cameras
}

if(one of the left or right node is having camera installed)
{
    then this current node is covered by one of the node and it should return the status covered to the parent 
}

else 
{
    here we fall only when we need to be covered by our parent 
    hence making request that kindly please cover me
    and return PleaseCover status 
}

and important point is if root returns the status of please cover than we do inc. ans 
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
    #define HasCamera 0
    #define Covered 1
    #define PleaseCover 2
    int ans;
    
    int dfs(TreeNode *root)
    {
        if(root==NULL)  return Covered;
        int left=dfs(root->left);
        int right=dfs(root->right);
        
        if(left==PleaseCover || right==PleaseCover)
        {
            ans++;
            return HasCamera;
        }
        
        if(left==HasCamera || right==HasCamera)
        {
            return Covered;
        }
        
        return PleaseCover;
    }
    
    int minCameraCover(TreeNode* root) {
        ans=0;
        int status=dfs(root);
        if(status==PleaseCover) ans++;
        return ans;
    }
};