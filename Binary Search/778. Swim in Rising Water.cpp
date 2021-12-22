/*
problem is basically to minimize the maximum value in any path starting from src to dest 
*/

class Solution {
public:
    
    bool possible(vector<vector<int>> &grid,int threshold)
    {
        // if(grid[0][0]>threshold)    return false;
        int n=grid.size(),x,y,dx,dy,i;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        vis[0][0]=true;
        q.push({0,0});
        int dir[5]={0,1,0,-1,0};
        
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            x=curr.first,y=curr.second;
            
            for(i=0;i<4;i++)
            {
                dx=x+dir[i];
                dy=y+dir[i+1];
                if(dx<0||dx>=n||dy<0||dy>=n||vis[dx][dy])   continue;
                
                if(grid[dx][dy]<=threshold)
                {
                    q.push({dx,dy});
                    vis[dx][dy]=true;
                }
            }
        }
        
        return vis[n-1][n-1];
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int low,high,mid,ans;
        low=grid[0][0],high=2500;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(possible(grid,mid))
            {
                ans=mid;
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};