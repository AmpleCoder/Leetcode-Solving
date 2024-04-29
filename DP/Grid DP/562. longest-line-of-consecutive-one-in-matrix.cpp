/*
    dp[i][j][0] --> max ones with horizontal ones
    dp[i][j][1] --> max ones with vertical ones
    dp[i][j][2] --> max ones with left anti dia ones
    dp[i][j][3] --> max ones with right anti dia ones
*/
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int dp[row][col][4];
        int result = 0;
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < col; i++){
            if(mat[0][i] == 1){
                dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = dp[0][i][3] = 1;
                if(i > 0){
                    dp[0][i][0] += dp[0][i-1][0];
                }
            }
        }

        for(int i = 0; i < row; i++){
            if(mat[i][0] == 1){
                dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = dp[i][0][3] = 1;
                if(i > 0){
                    dp[i][0][1] += dp[i-1][0][1];
                }
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(mat[i][j] == 1){
                    dp[i][j][0] = 1 + dp[i][j-1][0];
                    dp[i][j][1] = 1 + dp[i-1][j][1];
                    dp[i][j][2] = 1 + dp[i-1][j-1][2];
                    if(j + 1 < col){
                        dp[i][j][3] = 1 + dp[i-1][j+1][3];
                    }
                }
            }
        }

        for(int i = 1; i < row; i++){
            if(mat[i][0] == 1 && col > 1){
                dp[i][0][3] = 1 + dp[i - 1][1][3];
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                for(int k = 0; k < 4; k++){
                    result = max(result, dp[i][j][k]);
                }
            }
        }

        return result;
    }
};