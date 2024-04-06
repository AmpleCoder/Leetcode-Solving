/*
    inside hasValidPathUtil 
        first i'm defining my structure ki mei bottom aur right bindass call kr dunga 
        ab sabse phle we've to check ki currRow ya currCol kisi ka value row aur col limit se par hua ya nhi 
            agar hua to return false
            nhi hua to check curr cell ki value include krke balance kitta ban raha mera
        agar negative bana to return false
        agar positive bana then 
            check if we've reached the bottom right corner if yes then is balance == 0 or not accordingly value return krenge 
        ab bas dp laga do 

        follow up :
            number of possible balanced strings kitti banengi
*/

class Solution {
public:
    bool hasValidPathUtil(vector<vector<char>>& grid, int dp[101][101][201], int currRow, int currCol, int row, int col, int balance){
        if(currRow >= row || currCol >= col){
            return false;
        }

        if(grid[currRow][currCol] == '('){
            balance++;
        }

        else{
            balance--;
        }

        if(balance < 0){
            return false;
        }

        if(currRow == row - 1 && currCol == col - 1){
            return (balance == 0);
        }

        if(dp[currRow][currCol][balance] != -1){
            return dp[currRow][currCol][balance];
        }

        bool left, right;
        left = hasValidPathUtil(grid, dp, currRow + 1, currCol, row, col, balance);
        right = hasValidPathUtil(grid, dp, currRow, currCol + 1, row, col, balance);
        
        return dp[currRow][currCol][balance] = (left || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int dp[101][101][201];
        memset(dp, -1, sizeof(dp));
        int row = grid.size(), col = grid[0].size();

        return hasValidPathUtil(grid, dp, 0, 0, row, col, 0);
    }
};