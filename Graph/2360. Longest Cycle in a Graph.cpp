/*
try to solve this in generic graph
*/

class Solution {
public:
    int longestCycleLen;
    
    void dfs(vector<int> &edges,int node,vector<int> &stored,vector<bool> &visited)
    {
        if(node==-1)
        {
            return;
        }
        
        int size=stored.size();
        
        if(visited[node])
        {
            int occurence=-1;
            
            for(int i=0;i<size;i++)
            {
                if(node==stored[i])
                {
                    occurence=i;
                    break;
                }
            }
            
            if(occurence==-1)
            {
                return;
            }

            longestCycleLen=max(longestCycleLen,size-occurence);
            return;
        }
        
        visited[node]=true;
        stored.push_back(node);
        dfs(edges,edges[node],stored,visited);
    }
    
    int longestCycle(vector<int>& edges) {
        longestCycleLen=-1;
        int size=edges.size();
        vector<bool> visited(size,false);
        
        for(int i=0;i<size;i++)
        {
            if(edges[i]!=-1 && visited[i]==false)
            {
                vector<int> store;
                dfs(edges,i,store,visited);
            }
        }
        
        return longestCycleLen;
    }
};