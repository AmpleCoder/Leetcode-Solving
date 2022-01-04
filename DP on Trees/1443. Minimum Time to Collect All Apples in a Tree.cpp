/*
simple thoughts + simple implementation
*/

class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<bool> &hasApple,int src,int par){
        int childVal=0,ans=0;
        
        for(auto &child:adj[src]){
            if(child!=par){
                childVal=dfs(adj,hasApple,child,src);
                if(childVal!=0 || (childVal==0 && hasApple[child]==true)){
                    ans=ans+childVal+2;
                }
            }
        }
        
        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(100001);

        for(auto &edge:edges){
            int u,v;
            u=edge[0];
            v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans=dfs(adj,hasApple,0,-1);
        return ans;
    }
};