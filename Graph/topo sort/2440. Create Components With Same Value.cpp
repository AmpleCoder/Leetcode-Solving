/*
classy topo-sort + maths
*/

class Solution {
public:
    void bfs(vector<vector<int>> &graph,vector<int> nums,vector<int> indegree,int value,int &maxEdgeRemoved)
    {
        int size=indegree.size(),edgesRemoved=0;
        queue<int> q;
        
        for(int i=0;i<size;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int currVal=q.front();
            q.pop();
            if(nums[currVal]>value)
            {
                return;
            }
            
            if(nums[currVal]==value)
            {
                edgesRemoved++;
                for(auto &ngb:graph[currVal])
                {
                    indegree[ngb]--;
                    if(indegree[ngb]==1)
                    {
                        q.push(ngb);
                    }
                }
            }
            
            else
            {
                for(auto &ngb:graph[currVal])
                {
                    indegree[ngb]--;
                    nums[ngb]+=nums[currVal];
                    if(indegree[ngb]==1)
                    {
                        q.push(ngb);
                    }
                }
            }
        }
        
        maxEdgeRemoved=max(maxEdgeRemoved,edgesRemoved);
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int size=nums.size(),sum=0,firstFactor,secondFactor,maxEdgeRemoved=0;
        vector<vector<int>> graph(size);
        vector<int> indegree(size,0);
        
        for(auto &currVal:nums)
        {
            sum+=currVal;
        }
        
        for(auto &currEdge:edges)
        {
            int u=currEdge[0];
            int v=currEdge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        
        for(int i=1;i*i<=sum;i++)
        {
            if(sum%i==0)
            {
                firstFactor=sum/i;
                secondFactor=sum/firstFactor;
                bfs(graph,nums,indegree,firstFactor,maxEdgeRemoved);
                if(firstFactor!=secondFactor)
                {
                    bfs(graph,nums,indegree,secondFactor,maxEdgeRemoved);
                }
            }
        }
        
        
        return max(maxEdgeRemoved-1,0);
    }
};