/*
first instinct
	-> inorder traversal ke bad apne ko sorted list mil jayegi usse aapn map use krke har node ko replace kr skte corresponding  greater sum value se 
	
	smart approach
	->reverse inorder traversal with ek global variable le skte jo right se leke sum store krega and har node ki value ko replace kr skte
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
    TreeNode* convertBSTUtil(TreeNode* root,int &accSum) {
        if(root==NULL){
            return NULL;
        }
        
        convertBSTUtil(root->right,accSum);
        root->val+=accSum;
        accSum=root->val;
        convertBSTUtil(root->left,accSum);
        
        return root;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int accSum=0;
        convertBSTUtil(root,accSum);
        return root;
    }
};