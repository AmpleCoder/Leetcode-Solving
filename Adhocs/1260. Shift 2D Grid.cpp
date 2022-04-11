/*
need to go through optimised solution
*/

class Solution {
public:
    
    void move(vector<vector<int>>& grid){
        vector<int> lastRow;
        int row,col,i,j,lastEle;
        row=grid.size();
        col=grid[0].size();
        lastEle=grid[row-1][col-1];
        
        for(i=0;i<row;i++){
            lastRow.push_back(grid[i][col-1]);
        }
        
        for(i=0;i<row;i++){
            for(j=col-2;j>=0;j--){
                grid[i][j+1]=grid[i][j];
            }
        }
        
        for(i=1;i<row;i++){
            grid[i][0]=lastRow[i-1];
        }
        
        grid[0][0]=lastEle;
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i=0;i<k;i++){
            move(grid);
        }
        
        return grid;
    }
};