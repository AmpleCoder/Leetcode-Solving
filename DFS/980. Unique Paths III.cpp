/*
isme bactracking use kr rahe hein 
dhyan rahe sawal mei bola gaya hei ki har empty cell ke through walk honi chahiye 
*/

class Solution {
    int dirX[4]={-1,0,1,0};
    int dirY[4]={0,-1,0,1};
    
public:
    void dfs(vector<vector<int>>& grid,int x,int y,int &numberOfPaths,int row,int col,int &empty){
        
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]<0){
            return;
        }
        
        if(grid[x][y]==2){
            if(empty==0){
                numberOfPaths++;   
            }
            
            return;
        }
        
        grid[x][y]=-2;
        empty--;
        
        for(int i=0;i<4;i++){
            int dx=x+dirX[i];
            int dy=y+dirY[i];
            
            dfs(grid,dx,dy,numberOfPaths,row,col,empty);
        }
        
        grid[x][y]=0;
        empty++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size(),srcX,srcY,destX,destY,numberOfPaths=0,empty=1;
       
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 if(grid[i][j]==1){
                     srcX=i;
                     srcY=j;
                 }
                
                else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        
        dfs(grid,srcX,srcY,numberOfPaths,row,col,empty);
        return numberOfPaths;
    }
};