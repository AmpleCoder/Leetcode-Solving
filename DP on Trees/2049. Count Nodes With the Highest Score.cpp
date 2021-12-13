/*
not very much to explain here as it's easy to think here we need to modify a bit of sub tree size and fit this 
to get our answer 
if anyone feel elaborated explaination i'm ready to clear this for you
*/

class Solution {
public:
    vector<int> adj[100001];
    vector<int> sub;
    long long maxi;
    int count;
    int n;
    
    void dfs_size(int curr,int par)
    {
        int size=1;
        for(auto &ngb:adj[curr])
        {
            if(ngb!=par)
            {
                dfs_size(ngb,curr);
                size+=sub[ngb];
            }
        }
        
        sub[curr]=size;
    }
    
    void dfs_ans(int curr,int par)
    {
        long long currVal=1;
        
        for(auto &ngb:adj[curr])
        {
            if(ngb!=par)
            {
                dfs_ans(ngb,curr);
                currVal=currVal*sub[ngb];
            }
        }
        
        if(curr!=0)
            currVal*=(n-sub[curr]);
        
        if(currVal>maxi)
        {
            maxi=currVal;
            count=1;
        }
        
        else if(currVal==maxi)
        {
            count++;
        }
    }
    
    int countHighestScoreNodes(vector<int> &parents) {
        int size=parents.size(),i,u,v;
        n=size;
        
        for(i=0;i<size;i++)
        {
            if(parents[i]!=-1)
            {
                u=i,v=parents[i];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        sub.resize(100001,0);
        dfs_size(0,-1);
        maxi=count=0;
        dfs_ans(0,-1);
        return count;
    }
};