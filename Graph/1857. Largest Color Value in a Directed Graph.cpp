/*
here we need to tell the mvalue of max freq of any number in any directed path
follow up : how to print the path
it's a very good problem basically kinda tough

look at the code once i've solved on my own by using some hint
*/

class Solution {
public:
    vector<vector<int>> adj;
    
    bool bfs_topo(vector<int> indegree,int size)
    {
        int i;
        
        queue<int> q;
        vector<int> ans;
        
        for(i=0;i<size;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto &v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        
        return (ans.size()!=size);
    }
    
    int dfs(int node,char col,string &colors,vector<vector<int>> &dp)
    {
        if(dp[node][col-'a']!=-1)
        {
            return dp[node][col-'a'];
        }
        
        int maxNgb=0,currNgb,maxCount;
        
        for(auto &x:adj[node])
        {
            currNgb = dfs(x,col,colors,dp);
            maxNgb=max(maxNgb,currNgb);
        }
        
        maxCount=maxNgb;
        
        if(colors[node]==col)
        {
            maxCount++;
        }
        
        return dp[node][col-'a']=maxCount;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int size=colors.size(),i,ans=0,currCount;
        adj.resize(size);
        vector<int> indegree(size,0);
        queue<int> q;
        vector<vector<int>> dp(size,vector<int>(26,-1));
        
        for(auto &edge:edges)
        {
            int u,v;
            u=edge[0];
            v=edge[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        
        for(i=0;i<size;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        bool flag=bfs_topo(indegree,size);
        if(flag)
        {
            return -1;
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(char k='a';k<='z';k++)
            {
                if(dp[curr][k-'a']!=-1)
                {
                    currCount = dp[curr][k-'a'];
                }
                
                else
                {
                    currCount = dfs(curr,k,colors,dp);
                }
                
                ans=max(ans,currCount);
            }
        }
        
        return ans;
    }
};