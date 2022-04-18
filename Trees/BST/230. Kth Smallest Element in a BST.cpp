/*
solved via iterative inorder traversal
TC: O(height+k)
SC: O(height) 
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        
        while(true){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            
            //here we can do our work 
            root=s.top();
            k--;
            if(k==0){
                return root->val;
            }
            s.pop();
            
            root=root->right;
        }
    }
};