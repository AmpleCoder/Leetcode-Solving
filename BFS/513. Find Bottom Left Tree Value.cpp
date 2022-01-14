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
simple bfs problem 
*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int count,currLvlFirst,ans=-1;
        queue<TreeNode*> q;
        TreeNode *curr;
        
        q.push(root);
        
        while(!q.empty())
        {
            count=q.size();
            currLvlFirst=-10000000;
            
            for(int i=0;i<count;i++)
            {
                curr=q.front();
                q.pop();
                if(currLvlFirst==-10000000)
                {
                    currLvlFirst=curr->val;
                }
                
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            ans=currLvlFirst;
        }
        
        return ans;
    }
};