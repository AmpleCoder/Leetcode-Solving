/*
here my logic is very simple all i'm doing is first making sure that all values in my left subtree should be equal to 1
and same for right subtree 
and whatever extra value we'll be having (maybe positive or negative) it is going to be stored in the node of the  current value
hence doing post order traversal it's gauranteed to give the optimal results 
why as we're making sure that everything is fixed up in bottom up manner

here i'm augmenting the node's of a tree it's not a good practice to do so 
i'm thinking to update my solution without augmenting the tree 
once i figure it out i'll update my soltion 
thanks
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
    int ans=0;
    
    void dfs(TreeNode *root)
    {
        if(root!=NULL)
        {
            if(root->left!=NULL)
            {
                dfs(root->left);
                ans+=abs(root->left->val-1);
                root->val+=(root->left->val-1);
            }
            
            if(root->right!=NULL)
            {
                dfs(root->right);
                ans+=abs(root->right->val-1);
                root->val+=(root->right->val-1);
            }
        }
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};