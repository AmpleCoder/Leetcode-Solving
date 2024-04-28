/*
one of the std in and out dp problem 
here we ned to first compute the subtreeSize[node] for all nodes
then compute in[node] for all nodes and after that 
we've got the feel of how out[node] is computed simple not tough task 
only need is to visualize the in and out of par and deriving some formula out of it 
*/

class Solution {
public:
    int sub[30001];
    int in[30001];
    int out[30001];
    vector<int> adj[30001];
    
    void dfs_sub(int curr,int par)
    {
        int currSize=1;
        
        for(auto &ngb:adj[curr])
        {
            if(ngb!=par)
            {
                dfs_sub(ngb,curr);
                currSize+=sub[ngb];
            }
        }
        
        sub[curr]=currSize;
    }
    
    void dfs_in(int curr,int par)
    {
        int subSum=0;
        int inSum=0;
        
        for(auto &ngb:adj[curr])
        {
            if(ngb!=par)
            {
                dfs_in(ngb,curr);
                subSum+=sub[ngb];
                inSum+=in[ngb];
            }
        }
        
        in[curr]=subSum+inSum;
    }
    
    void dfs_out(int curr,int par,int n)
    {
        if(curr!=1)
        {
            int par_in=in[par]-(in[curr]+sub[curr])+(sub[par]-sub[curr]);
            int par_out=out[par]+(n-sub[par]);
            out[curr]=par_in+par_out;
        }
        
        for(auto &ngb:adj[curr]){
            if(ngb!=par){
                dfs_out(ngb,curr,n);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto &x:edges)
        {
            int u,v;
            u=x[0],v=x[1];
            u++,v++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs_sub(1,0);
        dfs_in(1,0);
        dfs_out(1,0,n);
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i]=in[i+1]+out[i+1];
        }
        
        return ans;
    }
};