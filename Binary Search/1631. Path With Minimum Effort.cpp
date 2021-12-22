/*
very beautiful problem which can be done using bs + dfs/bfs
try this problem later on with djikstra's , DSU and other approaches as well 
*/

class Solution {
public:
    
    bool possible(vector<vector<int>> &heights,int mid)
    {
        int row,col,dx,dy,x,y,i,j;
        row=heights.size(),col=heights[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        vis[0][0]=true;
        queue<pair<int,int>> q;
        q.push({0,0});
        int dir[5]={0,1,0,-1,0};
        
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            x=curr.first,y=curr.second;
            
            for(i=0;i<4;i++)
            {
                dx=x+dir[i],dy=y+dir[i+1];
                if(dx<0 || dx>=row || dy<0 || dy>=col || vis[dx][dy])   continue;
                
                if(abs(heights[x][y] - heights[dx][dy]) <= mid)
                {
                    q.push({dx,dy});
                    vis[dx][dy]=true;
                }
            }
        }
        
        return vis[row-1][col-1];
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo,hi,mid,ans;
        lo=0,hi=1000000;
        
        while(lo<=hi)
        {
            mid=lo+(hi-lo)/2;
            if(possible(heights,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;
    }
};