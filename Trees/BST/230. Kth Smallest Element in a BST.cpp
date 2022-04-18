/*
solved via iterative inorder traversal
TC: O(height+k)
SC: O(height) 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest
frequently, how would you optimize?
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

/*
TC: O(Height)
*/

class TreeNodeWithCount {
public:
    int val;
    int count;
    TreeNodeWithCount* left;
    TreeNodeWithCount* right;
    TreeNodeWithCount(int x) {val = x; count = 1;left=NULL;right=NULL;}
};

class Solution {
public:
    TreeNodeWithCount* buildTreeWithCount(TreeNode* root,int& n) {
        if (!root) return NULL;
        TreeNodeWithCount* rootWithCount = new TreeNodeWithCount(root->val);
        rootWithCount->left = buildTreeWithCount(root->left,n);
        rootWithCount->count = n++;
        rootWithCount->right = buildTreeWithCount(root->right,n);
        return rootWithCount;
    }
 
    int kthSmallest(TreeNodeWithCount* rootWithCount, int k) {
        if (rootWithCount->count > k) 
            return kthSmallest(rootWithCount->left, k);
        else if (rootWithCount->count == k) 
            return rootWithCount->val;
        else
            return kthSmallest(rootWithCount->right, k);
    }
 
     
    int kthSmallest(TreeNode* root, int k) {
		int n = 1;
        TreeNodeWithCount* rootWithCount = buildTreeWithCount(root,n);
        return kthSmallest(rootWithCount, k);
    }
};