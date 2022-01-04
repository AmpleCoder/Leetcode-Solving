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
nice problem at each node we need to check whether it'll maximize our answer or not + some logical decisions 
*/

#define pii pair<int,int>

class Solution {
public:
    pii dfs(TreeNode *root,int &ans)
    {
        if(root==NULL)  return {0,0};
        pii left=dfs(root->left,ans);
        pii right=dfs(root->right,ans);
        int l,r;
        l=1+left.second;
        r=1+right.first;
        ans=max({ans,l,r});
        return {l,r};
    }
    
    int longestZigZag(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans-1;
    }
};