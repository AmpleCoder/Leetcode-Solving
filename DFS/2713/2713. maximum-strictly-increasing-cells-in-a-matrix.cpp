/*
    approach:
        below is the most trivial approach in order to optimise it refer to the diagram 
*/

class Solution {
public:
    int dfs(vector<vector<int>> &mat, int currX, int currY, int row, int col, vector<vector<int>> &dp){
        if(dp[currX][currY] != -1){
            return dp[currX][currY];
        }

        int result = 1;

        //calculate for col
        for(int i = 0; i < row; i++){
            if(mat[currX][currY] < mat[i][currY]){
                int currResult;

                if(dp[i][currY] != -1){
                    currResult = 1 + dp[i][currY];
                }

                else{
                    currResult = 1 + dfs(mat, i, currY, row, col, dp);
                }
                
                result = max(result, currResult);
            }
        }

        //calculate for row
        for(int i = 0; i < col; i++){
            if(mat[currX][currY] < mat[currX][i]){
                int currResult;

                if(dp[currX][i] != -1){
                    currResult = 1 + dp[currX][i];
                }

                else{
                    currResult = 1 + dfs(mat, currX, i, row, col, dp);
                }
                
                result = max(result, currResult);
            }
        }

        return dp[currX][currY] = result; 
    }

    int maxIncreasingCells(vector<vector<int>>& mat) {
        int row, col, maxIncCellSize = 1;
        row = mat.size();
        col = mat[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                //if answer for this cell is not recorded call for it
                if(dp[i][j] == -1){
                    dfs(mat, i, j, row, col, dp);
                    maxIncCellSize = max(maxIncCellSize, dp[i][j]);
                }
            }
        }

        return maxIncCellSize;
    }
};

/*
    approach:
        sort krke best results ko store krke solve kiya easy to understand
*/

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int row, col, maxIncCellSize = 1;
        row = mat.size();
        col = mat[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));  
        vector<int> result(row + col, 0);
        map<int, vector<int>> valueToIndex;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int currIndex = i * col + j;
                valueToIndex[mat[i][j]].push_back(currIndex);
            }
        }

        for(auto &[val, posVec]: valueToIndex){
            //for each position we'll update the max steps 
            for(auto &currPos: posVec){
                int currRow = currPos / col;
                int currCol = currPos % col;

                dp[currRow][currCol] = max(result[currRow], result[currCol + row]) + 1;
            }

            //update the best result for the row and col
            for(auto &currPos: posVec){
                int currRow = currPos / col;
                int currCol = currPos % col;

                result[currRow] = max(result[currRow], dp[currRow][currCol]);
                result[currCol + row] = max(result[currCol + row], dp[currRow][currCol]);
            }
        }

        return *max_element(result.begin(), result.end());
    }
};