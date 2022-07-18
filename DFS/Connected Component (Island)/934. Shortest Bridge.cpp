/*
ek bridge pkda uske through ms-bfs laga diya 
*/
class Solution {
    int dirX[4]={-1,0,1,0};
    int dirY[4]={0,1,0,-1};
    
public:
    bool isValid(vector<vector<int>> &grid,vector<vector<bool>> &visited,int &x,int &y,int &row,int &col)
    {
        return ((x>=0 && x<row) && (y>=0 && y<col) && visited[x][y]==false && grid[x][y]==1);
    }
    
    bool isNotValid(vector<vector<int>> &grid,vector<vector<bool>> &visited,int &x,int &y,int &row,int &col)
    {
        return !((x>=0 && x<row) && (y>=0 && y<col) && visited[x][y]==false);
    }
    
    void dfs(vector<vector<int>> &grid,int currX,int currY,vector<vector<bool>> &visited,vector<vector<int>> &distance,int &row,int &col)
    {
        visited[currX][currY]=true;
        distance[currX][currY]=0;
        
        for(int i=0;i<4;i++)
        {
            int newX=currX+dirX[i];
            int newY=currY+dirY[i];
            if(isValid(grid,visited,newX,newY,row,col))
            {
                dfs(grid,newX,newY,visited,distance,row,col);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> distance(row,vector<int>(col,-1));
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int minNumOfZerosToBeFlipped=INT_MAX;
        bool flag=0;
        queue<vector<int>> q;
        
        for(int i=0;i<row && flag==0;i++)
        {
            for(int j=0;j<col && flag==0;j++)
            {
                if(visited[i][j]==false && grid[i][j]==1)
                {
                    flag=1;
                    dfs(grid,i,j,visited,distance,row,col);
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(distance[i][j]==0)
                {
                    q.push({i,j,0});
                }
            }
        }
        
        while(!q.empty())
        {
            vector<int> currMatric=q.front();
            q.pop();
            int currX=currMatric[0];
            int currY=currMatric[1];
            int currDist=currMatric[2];
            
            for(int i=0;i<4;i++)
            {
                int newX=currX+dirX[i];
                int newY=currY+dirY[i];
                
                if(isNotValid(grid,visited,newX,newY,row,col))
                {
                    continue;
                }
                
                visited[newX][newY]=true;
                distance[newX][newY]=currDist+1;
                q.push({newX,newY,currDist+1});
            }
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // cout<<distance[i][j]<<" ";
                
                if(distance[i][j]!=0 && grid[i][j]==1)
                {
                    minNumOfZerosToBeFlipped=min(minNumOfZerosToBeFlipped,distance[i][j]);
                }
            }
            
            // cout<<endl;
        }
        
        return minNumOfZerosToBeFlipped-1;
    }
};