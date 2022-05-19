/*
simple to understand
*/

class Solution {
    int dirX[4]={0,-1,0,1};
    int dirY[4]={1,0,-1,0};
    
public:
    void dfs(vector<vector<int>>& matrix,int x,int y,vector<vector<int>> &dp,int row,int col){
        int dx,dy,maxi=1,i;
        
        for(i=0;i<4;i++){
            dx=x+dirX[i];
            dy=y+dirY[i];
            
            if(dx<0 || dx>=row || dy<0 || dy>=col || matrix[dx][dy] <= matrix[x][y]){
                continue;
            }
            
            if(dp[dx][dy]==-1){
                dfs(matrix,dx,dy,dp,row,col);
            }
            
            maxi=max(maxi,1+dp[dx][dy]);
        }
        
        dp[x][y]=maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size(),i,j,maxi=INT_MIN;
        vector<vector<int>> dp(row,vector<int>(col,-1));
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(dp[i][j]==-1){
                    dfs(matrix,i,j,dp,row,col);
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        
        return maxi;
    }
};