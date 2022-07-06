class Solution {
    int dirX[4]={-1,0,1,0};
    int dirY[4]={0,-1,0,1};
    
public:
    long long dfs(vector<vector<int>> &grid,int currX,int currY,int row,int col,int prevVal,int mod,vector<vector<int>> &dp)
    {
        if(currX<0||currX>=row||currY<0||currY>=col||grid[currX][currY]<=prevVal)
        {
            return 0;
        }
        
        if(dp[currX][currY]!=-1)
        {
            return dp[currX][currY];
        }
        
        long long currPathCount=1;
        
        for(int k=0;k<4;k++)
        {
            int newX=dirX[k]+currX;
            int newY=dirY[k]+currY;
            
            currPathCount=(currPathCount+dfs(grid,newX,newY,row,col,grid[currX][currY],mod,dp))%mod;
        }
        
        return dp[currX][currY]=currPathCount;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size(),mod=(int)1e9+7;
        long long pathCount=0,localPathCount;
        vector<vector<int>> dp(row,vector<int>(col,-1));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // if(dp[i][j]==-1)
                // {
                    localPathCount=dfs(grid,i,j,row,col,INT_MIN,mod,dp);
                    pathCount=(pathCount+localPathCount)%mod;
                // }
            }
        }
        
        return pathCount;
    }
};