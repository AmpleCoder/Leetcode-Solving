/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
good tree problem 
here we need to tell all k node distances from a given node in tree 
follow up : k node siblings 
*/

class Solution {
public:
    
    void build(TreeNode *curr,TreeNode *par,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        if(curr==NULL)
        {
            return;
        }
        
        parent[curr]=par;
        build(curr->left,curr,parent);
        build(curr->right,curr,parent);
    }
    
    void bfs(TreeNode *curr,unordered_map<TreeNode*,TreeNode*> &par,vector<int> &ans,int k)
    {
        queue<pair<TreeNode*,int>> q;
        q.push({curr,0});
        TreeNode *currNode;
        int dist;
        unordered_map<TreeNode*,bool> visited;
        
        while(!q.empty())
        {
            pair<TreeNode*,int> front=q.front();
            q.pop();
            currNode=front.first;
            dist=front.second;
            visited[currNode]=true;
            if(dist>k)  break;
            
            if(dist==k)
            {
                ans.push_back(currNode->val);
            }
            
            if(currNode->left && visited[currNode->left]==false)
            {
                q.push({currNode->left,dist+1});
            }
            
            if(currNode->right && visited[currNode->right]==false)
            {
                q.push({currNode->right,dist+1});
            }
            
            if(par[currNode] && visited[par[currNode]]==false)
            {
                q.push({par[currNode],dist+1});
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        build(root,NULL,par);
        vector<int> ans;
        bfs(target,par,ans,k);
        return ans;
    }
};