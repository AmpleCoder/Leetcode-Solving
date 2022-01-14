/*
this is medium version of the good problem 
here given a tree we need to return number of edges to be reversed such that root can be reached via every other nodes

if we think of dp on trees here then we'll get it at first glance

follow up : what if given a graph then 
*/

class Solution {
public:
    vector<vector<int>> adj;
    
    int dfs(int curr,int par)
    {
        int ans=0;
        
        for(auto &ngb:adj[curr])
        {
            if(abs(ngb)!=par)
            {   
                ans+=dfs(abs(ngb),curr)+(ngb>0);
            }
        }
        
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        
        for(auto &edges:connections)
        {
            int u=edges[0];
            int v=edges[1];
            adj[u].push_back(v);
            adj[v].push_back(-u);
        }
        
        int ans=dfs(0,-1);
        return ans;
    }
};