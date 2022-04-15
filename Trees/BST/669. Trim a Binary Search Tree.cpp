/*

If the root value in the range [L, R]
      we need return the root, but trim its left and right subtree;
else if the root value < L
      because of binary search tree property, the root and the left subtree are not in range;
      we need return trimmed right subtree.
else
      similarly we need return trimmed left subtree.

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->val>=low && root->val<=high){
            TreeNode *leftTrimedTree=trimBST(root->left,low,high);
            TreeNode *rightTrimedTree=trimBST(root->right,low,high);
            root->left=leftTrimedTree;
            root->right=rightTrimedTree;
            return root;
        }
        
        else if(root->val<low){
            TreeNode *rightTrimedTree=trimBST(root->right,low,high);
            return rightTrimedTree;
        }
        
        else{
            TreeNode *leftTrimedTree=trimBST(root->left,low,high);
            return leftTrimedTree;
        }
    }
};