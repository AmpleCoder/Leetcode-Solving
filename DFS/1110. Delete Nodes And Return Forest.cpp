/*
this is one of the intuitive problem where before solving this we need to have a deep understanding of where things might went wrong
(if we delete certain node which is to be deleted whoses level is lesser than the other to be deleted)
so folowing this we can simple maintain the levels of the nodes and after that we can sort the nodes on the basis of decreasing levels
of nodes to be deleted then after that we can maintains parents of each nodes after that and after that things are pretty simple only case we 
need to consider is for root at the end 
try thinking this you can simply do that :)
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
    vector<int> level;
    vector<TreeNode*> ans;
    unordered_map<TreeNode*,TreeNode*> parent;
    unordered_map<int,TreeNode*> mapping;
    
    void dfs_lvl(TreeNode *root,TreeNode *par,int lvl)
    {
        parent[root]=par;
        
        if(root!=NULL)
        {
            mapping[root->val]=root;
            level[root->val]=lvl;
            dfs_lvl(root->left,root,lvl+1);
            dfs_lvl(root->right,root,lvl+1);
        }
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        level.resize(1001,0);
        dfs_lvl(root,NULL,0);
        sort(to_delete.begin(),to_delete.end(),[&](const int &a,const int &b){
            return level[a]>level[b];
        } );
        
        bool flag=1;
        
        for(auto &x:to_delete)
        {
            TreeNode *ref=mapping[x];
            TreeNode *par=parent[ref];
            TreeNode *leftChild=ref->left;
            TreeNode *rightChild=ref->right;
            
            if(leftChild!=NULL)
            {
                ans.push_back(leftChild);
            }
            
            if(rightChild!=NULL)
            {
                ans.push_back(rightChild);
            }
            
            if(par==NULL)
            {
                flag=0;
                break;
            }
            
            if(par->left!=NULL && par->left->val==x)
            {
                par->left=NULL;
            }
            
            else if(par->right!=NULL && par->right->val==x)
            {
                par->right=NULL;
            }
        }
        
        if(flag==1)
        {
            ans.push_back(root);
        }
        
        return ans;
    }
};