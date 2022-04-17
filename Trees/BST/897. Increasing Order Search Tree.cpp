/*
code is simple to understand 
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
    void increasingBSTUtil(TreeNode* root,TreeNode** previous,TreeNode** result){
        if(root==NULL){
            return;
        }
        
        increasingBSTUtil(root->left,previous,result);
        
        //here we'll adjust nodes
        if((*result)==NULL){
            (*result)=root;
        }
        
        else{
            (*previous)->right=root;
        }
        
        (*previous)=root;
        root->left=NULL;
        
        increasingBSTUtil(root->right,previous,result);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *previous,*result;
        previous=result=NULL;
        increasingBSTUtil(root,&previous,&result);
        return result;
    }
};