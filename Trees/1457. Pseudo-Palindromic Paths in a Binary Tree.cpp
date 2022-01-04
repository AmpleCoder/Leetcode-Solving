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
    
    bool isPali(vector<int> &freq)
    {
        int i,c=0;
        
        for(i=0;i<10;i++)
        {
            // cout<<freq[i]<<" ";
            c=c+freq[i]%2;
        }
        
        // cout<<endl;
        
        return c<=1;
    }
    
    void dfs(TreeNode *root,vector<int> &freq,int &ans)
    {
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL)
        {
            freq[root->val]++;
            if(isPali(freq))
            {
                ans++;
            }
            freq[root->val]--;
            return;
        }
        
        freq[root->val]++;
        dfs(root->left,freq,ans);
        dfs(root->right,freq,ans);
        freq[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans=0;
        dfs(root,freq,ans);
        return ans;
    }
};

//method 2: using bitset
class Solution {
public:
    void dfs(TreeNode *root,bitset<10> &b,int &ans)
    {
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL)
        {
            b[root->val]=b[root->val] ^ 1;
            if(b.count()<=1)
            {
                ans++;
            }
            b[root->val]=b[root->val] ^ 1;
            return;
        }
        
        b[root->val]=b[root->val] ^ 1;
        dfs(root->left,b,ans);
        dfs(root->right,b,ans);
        b[root->val]=b[root->val] ^ 1;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<10> b;
        int ans=0;
        dfs(root,b,ans);
        return ans;
    }
};

/*
this problem can be done using iterative + recursive preorder as well 
and to solve this in constant space one has to use morris traversals(study it make it's template)
*/